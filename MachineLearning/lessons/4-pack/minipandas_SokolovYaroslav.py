import csv

def shape(func):
    def decor(*args, **kwargs):
        result = func(*args, **kwargs)
        print(f'Table with shape {len(result)}x{len(result[0].keys())}')
        return result
    return decor

# with open('people.csv', 'w', newline='') as file:
#     csv_file = csv.writer(file)
#     csv_file.writerow(['name', 'age', 'city'])
#     csv_file.writerow(['Alice', '23', 'London'])
#     csv_file.writerow(['Bob', '30', 'Paris'])
#     csv_file.writerow(['Charlie', '17', 'London'])
@shape
def read_csv(filename, dtype=None):
    with open(filename, newline='') as f:
        reader = csv.DictReader(f)
        fieldnames = reader.fieldnames

        if dtype is not None:
            for col in dtype:
                if col not in fieldnames:
                    raise ValueError("Unknown column in dtype")

        rows = []
        for row in reader:
            new_row = dict(row)
            if dtype is not None:
                for col, func in dtype.items():
                    value = new_row[col]
                    try:
                        new_row[col] = func(value)
                    except ValueError:
                        raise ValueError(f"Cannot convert value '{value}' in column '{col}' to {dtype[col].__name__}")
            rows.append(new_row)
    return rows

def head(data, n=5):
    if n < 0:
        raise ValueError('n must be non-negative')
    return data[:n]
@shape

def filter_rows(data, condition):
    return [v for v in data if condition(v)]
#   return filter(condition, data)

def select_columns(data, columns):
    if not data:
        return []

    exists_cols = set(data[0].keys())

    for select_col in columns:
        if select_col not in exists_cols:
            raise ValueError(f"Unknown column: '{select_col}'")

    result = []
    for row in data:
        filtered_row = {}
        for key, value in row.items():
            if key in columns:
                filtered_row[key] = value
        result.append(filtered_row)

    return result

def add_column(data, name, func):
    exists_cols = data[0].keys()
    if name in exists_cols:
        raise ValueError("Column already exists")

    result = []
    for row in data:
        row_data = row.copy()
        row_data[name] = func(row)
        result.append(row_data)

    return result

def aggregate(data, column, func):
    exists_cols = data[0].keys()
    if column not in exists_cols: raise ValueError("Unknown column")
    return func([row[column] for row in data])

def column_sum(data, column):
    return aggregate(data, column, sum)

def column_min(data, column):
    return aggregate(data, column, min)

def column_max(data, column):
    return aggregate(data, column, max)

def column_mean(data, column):
    return aggregate(data, column, lambda values: sum(values) / len(values))

def unique(data, column):
    return aggregate(data, column, lambda values: list(set(values)))

def value_counts(data, column):
    return aggregate(data, column, lambda values: {value: values.count(value) for value in set(values)})

def iter_csv(file_name, dtype=None):
    with open(file_name, 'r') as file:
        cols = file.readline().replace('\n', '').split(',')

        if not (dtype is None):
            for typed_col in dtype.keys():
                if typed_col not in cols: raise ValueError("Unknown column in dtype")

        while True:
            raw_row = file.readline()
            if not raw_row: break
            row = raw_row.replace('\n', '').split(',')
            if len(row) != len(cols): raise ValueError('Incorrect values count')
            row_data = {}
            for col_i in range(len(cols)):
                value = row[col_i]
                col = cols[col_i]

                if not (dtype is None) and col in dtype:
                    try:
                        value = dtype[col](value)
                    except:
                        raise ValueError(f"Cannot convert value '{value}' in column '{col}' to {dtype[col].__name__}")

                row_data[col] = value

            yield row_data
