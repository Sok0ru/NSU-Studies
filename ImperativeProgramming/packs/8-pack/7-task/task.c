#include <stdio.h>
#include <string.h>

typedef struct LongNum_s
{
    int len;
    int arr[2005];
} LongNum;

void read_num(LongNum *num, char *str)
{
    num->len = strlen(str);

    for (int i = 0; i < num->len; ++i)
        num->arr[i] = str[num->len - i - 1] - '0';
}

void mult_num(LongNum *result, const LongNum *first, const LongNum *second)
{
    result->len = first->len + second->len;

    for (int i = 0; i < result->len; ++i)
        result->arr[i] = 0;

    for (int i = 0; i < first->len; ++i)
    {
        int carry = 0;

        for (int j = 0; j < second->len; ++j)
        {
            int result_part = result->arr[i + j] + first->arr[i] * second->arr[j] + carry;

            result->arr[i + j] = result_part % 10;
            carry = result_part / 10;
        }
        result->arr[i + second->len] += carry;
    }

    while (result->len > 1 && result->arr[result->len - 1] == 0)
        --result->len;
}

void print_result(const LongNum *num)
{
    for (int i = num->len - 1; i >= 0; --i)
        printf("%d", num->arr[i]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char first[1005];
    char second[1005];

    scanf("%1000s %1000s", first, second);

    LongNum first_num;
    LongNum second_num;
    LongNum result;

    read_num(&first_num, first);
    read_num(&second_num, second);

    mult_num(&result, &first_num, &second_num);

    print_result(&result);

    return 0;
}