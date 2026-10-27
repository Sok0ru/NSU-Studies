"""Run: python -m unittest discover -s lessons/4-pack -p 'test_*.py' -v.

expectedFailure marks known bugs; remove the marker after fixing the code.
"""

import contextlib
import copy
import csv
import importlib.util
import io
from pathlib import Path
import tempfile
import unittest
import sys
from pprint import pprint


MODULE_PATH = Path(__file__).with_name('minipandas_SokolovYaroslav.py')
SPEC = importlib.util.spec_from_file_location('minipandas', MODULE_PATH)
mp = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(mp)


class MiniPandasTests(unittest.TestCase):
    def setUp(self):
        self.data = [
            {'name': 'Alice', 'age': 23, 'city': 'London'},
            {'name': 'Bob', 'age': 30, 'city': 'Paris'},
            {'name': 'Charlie', 'age': 17, 'city': 'London'},
        ]
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        self.path = Path(directory.name) / 'people.csv'
        self.write_csv(self.data)

    def write_csv(self, rows):
        with self.path.open('w', newline='') as stream:
            writer = csv.DictWriter(stream, fieldnames=['name', 'age', 'city'])
            writer.writeheader()
            writer.writerows(rows)

    def read(self, **kwargs):
        with contextlib.redirect_stdout(io.StringIO()):
            return mp.read_csv(self.path, **kwargs)

    def test_read_csv_strings_by_default(self):
        expected = [dict(row, age=str(row['age'])) for row in self.data]
        self.assertEqual(self.read(), expected)

    def test_read_csv_converts_selected_columns(self):
        self.assertEqual(self.read(dtype={'age': int}), self.data)

    def test_read_csv_prints_shape(self):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            mp.read_csv(self.path)
        self.assertEqual(output.getvalue(), 'Table with shape 3x3\n')

    def test_read_csv_unknown_dtype_column(self):
        with self.assertRaisesRegex(ValueError, 'Unknown column in dtype'):
            self.read(dtype={'missing': int})

    def test_read_csv_invalid_conversion(self):
        self.write_csv([dict(self.data[0], age='invalid')])
        with self.assertRaisesRegex(ValueError, "Cannot convert value 'invalid' in column 'age' to int"):
            self.read(dtype={'age': int})

    def test_read_csv_missing_file(self):
        with self.assertRaises(FileNotFoundError):
            mp.read_csv(self.path.with_name('missing.csv'))

    def test_read_csv_quoted_fields(self):
        rows = [dict(self.data[0], city='London, UK', name='Alice "A"\nSmith')]
        self.write_csv(rows)
        self.assertEqual(self.read(dtype={'age': int}), rows)

    def test_head_sizes(self):
        for n in (0, 1, 2, 3, 10):
            with self.subTest(n=n):
                self.assertEqual(mp.head(self.data, n), self.data[:n])
        self.assertEqual(mp.head([]), [])
        self.assertEqual(mp.head(self.data), self.data)

    def test_head_default_is_five(self):
        self.assertEqual(mp.head(list(range(8))), list(range(5)))

    def test_head_negative_size(self):
        with self.assertRaisesRegex(ValueError, 'n must be non-negative'):
            mp.head(self.data, -1)

    def test_filter_rows_and_shape(self):
        original = copy.deepcopy(self.data)
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            result = mp.filter_rows(self.data, lambda row: row['age'] >= 18)
        self.assertEqual(result, self.data[:2])
        self.assertEqual(output.getvalue(), 'Table with shape 2x3\n')
        self.assertEqual(self.data, original)

    def test_select_columns(self):
        original = copy.deepcopy(self.data)
        result = mp.select_columns(self.data, ['name', 'city'])
        self.assertEqual(result, [{'name': row['name'], 'city': row['city']} for row in self.data])
        self.assertEqual(self.data, original)
        self.assertIsNot(result[0], self.data[0])

    def test_select_columns_empty_inputs(self):
        self.assertEqual(mp.select_columns([], ['name']), [])
        self.assertEqual(mp.select_columns(self.data, []), [{}, {}, {}])

    def test_select_columns_unknown_column(self):
        with self.assertRaisesRegex(ValueError, "Unknown column: 'missing'"):
            mp.select_columns(self.data, ['missing'])

    def test_add_column_does_not_mutate_input(self):
        original = copy.deepcopy(self.data)
        result = mp.add_column(self.data, 'adult', lambda row: row['age'] >= 18)
        self.assertEqual(result, [dict(row, adult=row['age'] >= 18) for row in self.data])
        self.assertEqual(self.data, original)
        self.assertIsNot(result[0], self.data[0])

    def test_add_existing_column(self):
        with self.assertRaisesRegex(ValueError, 'Column already exists'):
            mp.add_column(self.data, 'age', lambda row: 0)

    def test_aggregate_custom_function(self):
        self.assertEqual(mp.aggregate(self.data, 'name', lambda values: ', '.join(values)), 'Alice, Bob, Charlie')

    def test_numeric_aggregations(self):
        for function, expected in [(mp.column_sum, 70), (mp.column_min, 17), (mp.column_max, 30), (mp.column_mean, 70 / 3)]:
            with self.subTest(function=function.__name__):
                self.assertAlmostEqual(function(self.data, 'age'), expected)

    def test_aggregations_with_negative_and_float_values(self):
        rows = [{'x': -2.5}, {'x': 0.0}, {'x': 4.0}]
        self.assertEqual(mp.column_sum(rows, 'x'), 1.5)
        self.assertEqual(mp.column_min(rows, 'x'), -2.5)
        self.assertEqual(mp.column_max(rows, 'x'), 4.0)
        self.assertEqual(mp.column_mean(rows, 'x'), 0.5)

    def test_unique_and_value_counts(self):
        self.assertCountEqual(mp.unique(self.data, 'city'), ['London', 'Paris'])
        self.assertEqual(mp.value_counts(self.data, 'city'), {'London': 2, 'Paris': 1})

    def test_aggregations_unknown_column(self):
        for function in (mp.column_sum, mp.column_min, mp.column_max, mp.column_mean, mp.unique, mp.value_counts):
            with self.subTest(function=function.__name__):
                with self.assertRaisesRegex(ValueError, 'Unknown column'):
                    function(self.data, 'missing')

    def test_iter_csv_strings_and_conversion(self):
        self.assertEqual(list(mp.iter_csv(self.path)), [dict(row, age=str(row['age'])) for row in self.data])
        self.assertEqual(list(mp.iter_csv(self.path, dtype={'age': int})), self.data)

    def test_iter_csv_is_lazy(self):
        self.path.write_text('name,age,city\nAlice,23,London\nBob,invalid,Paris\n')
        rows = mp.iter_csv(self.path, dtype={'age': int})
        self.addCleanup(rows.close)
        self.assertIs(iter(rows), rows)
        self.assertEqual(next(rows), self.data[0])
        with self.assertRaisesRegex(ValueError, 'Cannot convert value'):
            next(rows)

    def test_iter_csv_unknown_dtype_column(self):
        with self.assertRaisesRegex(ValueError, 'Unknown column in dtype'):
            list(mp.iter_csv(self.path, dtype={'missing': int}))

    def test_iter_csv_incorrect_field_count(self):
        for row in ('Alice,23', 'Alice,23,London,extra'):
            with self.subTest(row=row):
                self.path.write_text('name,age,city\n' + row + '\n')
                with self.assertRaisesRegex(ValueError, 'Incorrect values count'):
                    list(mp.iter_csv(self.path))

    def test_iter_csv_header_only(self):
        self.write_csv([])
        self.assertEqual(list(mp.iter_csv(self.path)), [])

    @unittest.expectedFailure
    def test_read_csv_header_only_should_return_empty_list(self):
        # BUG: shape indexes result[0] even when there are no rows.
        self.write_csv([])
        self.assertEqual(self.read(), [])

    @unittest.expectedFailure
    def test_filter_without_matches_should_return_empty_list(self):
        # BUG: shape cannot print the dimensions of an empty result.
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(mp.filter_rows(self.data, lambda row: False), [])

    @unittest.expectedFailure
    def test_iter_csv_should_support_quoted_commas(self):
        # BUG: splitting on commas does not implement CSV quoting.
        rows = [dict(self.data[0], city='London, UK')]
        self.write_csv(rows)
        self.assertEqual(list(mp.iter_csv(self.path, dtype={'age': int})), rows)


def review(function_name):
    """Наглядные примеры: --review head или --review all."""
    data = [
        {'name': 'Alice', 'age': 23, 'city': 'London'},
        {'name': 'Bob', 'age': 30, 'city': 'Paris'},
        {'name': 'Charlie', 'age': 17, 'city': 'London'},
    ]

    def check(call, function, expected, unordered=False):
        print('\nВызов:', call)
        actual = function()
        print('Ожидаемый результат:')
        pprint(expected, sort_dicts=False)
        print('Фактический результат:')
        pprint(actual, sort_dicts=False)
        if unordered:
            unittest.TestCase().assertCountEqual(actual, expected)
        else:
            unittest.TestCase().assertEqual(actual, expected)
        print('Проверка пройдена')

    cases = {
        'head': ("head(data, 2)", lambda: mp.head(data, 2), data[:2]),
        'filter_rows': (
            "filter_rows(data, lambda row: row['age'] >= 18)",
            lambda: mp.filter_rows(data, lambda row: row['age'] >= 18), data[:2]),
        'select_columns': (
            "select_columns(data, ['name'])",
            lambda: mp.select_columns(data, ['name']),
            [{'name': 'Alice'}, {'name': 'Bob'}, {'name': 'Charlie'}]),
        'add_column': (
            "add_column(data, 'adult', lambda row: row['age'] >= 18)",
            lambda: mp.add_column(data, 'adult', lambda row: row['age'] >= 18),
            [dict(data[0], adult=True), dict(data[1], adult=True), dict(data[2], adult=False)]),
        'aggregate': (
            "aggregate(data, 'name', lambda values: ', '.join(values))",
            lambda: mp.aggregate(data, 'name', lambda values: ', '.join(values)),
            'Alice, Bob, Charlie'),
        'column_sum': ("column_sum(data, 'age')", lambda: mp.column_sum(data, 'age'), 70),
        'column_min': ("column_min(data, 'age')", lambda: mp.column_min(data, 'age'), 17),
        'column_max': ("column_max(data, 'age')", lambda: mp.column_max(data, 'age'), 30),
        'column_mean': ("column_mean(data, 'age')", lambda: mp.column_mean(data, 'age'), 70 / 3),
        'unique': ("unique(data, 'city')", lambda: mp.unique(data, 'city'), ['London', 'Paris']),
        'value_counts': (
            "value_counts(data, 'city')", lambda: mp.value_counts(data, 'city'),
            {'London': 2, 'Paris': 1}),
    }
    names = ['read_csv', *cases, 'iter_csv', 'shape']
    if function_name not in names + ['all']:
        raise SystemExit('Доступные примеры: ' + ', '.join(names + ['all']))

    for name in names if function_name == 'all' else [function_name]:
        print('\n===', name, '===')
        print('Входные данные:')
        pprint(data, sort_dicts=False)
        original = copy.deepcopy(data)
        if name in ('read_csv', 'iter_csv'):
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / 'people.csv'
                with path.open('w', newline='') as stream:
                    writer = csv.DictWriter(stream, fieldnames=['name', 'age', 'city'])
                    writer.writeheader()
                    writer.writerows(data)
                print('Содержимое CSV:')
                print(path.read_text())
                if name == 'read_csv':
                    check("read_csv(path, dtype={'age': int})",
                          lambda: mp.read_csv(path, dtype={'age': int}), data)
                    check('read_csv(path): без dtype возраст остаётся строкой',
                          lambda: mp.read_csv(path),
                          [dict(row, age=str(row['age'])) for row in data])
                else:
                    def read_one_at_a_time():
                        rows = []
                        for row in mp.iter_csv(path, dtype={'age': int}):
                            print('Получена следующая строка:', row)
                            rows.append(row)
                        return rows
                    check("iter_csv(path, dtype={'age': int})",
                          read_one_at_a_time, data)
        elif name == 'shape':
            @mp.shape
            def table():
                return data

            def decorated_call():
                output = io.StringIO()
                with contextlib.redirect_stdout(output):
                    result = table()
                unittest.TestCase().assertEqual(result, data)
                return output.getvalue()

            check('@shape: table() возвращает таблицу и печатает её размер',
                  decorated_call, 'Table with shape 3x3\n')
        else:
            check(*cases[name], unordered=name == 'unique')
        unittest.TestCase().assertEqual(data, original)


if __name__ == '__main__':
    if len(sys.argv) >= 2 and sys.argv[1] == '--review':
        if len(sys.argv) != 3:
            raise SystemExit('Пример: python test_minipandas.py --review head')
        review(sys.argv[2])
    else:
        unittest.main()
