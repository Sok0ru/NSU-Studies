#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LongNum_s
{
    int len;
    int arr[500];
} LongNum;

void add_struct(LongNum *result, const LongNum *num_a, const LongNum *num_b)
{
    int rank = 0;
    int max_len = num_a->len > num_b->len ? num_a->len : num_b->len;

    for (int i = 0; i < max_len; ++i)
    {
        int digit_a = 0;
        int digit_b = 0;

        if (i < num_a->len)
            digit_a = num_a->arr[i];

        if (i < num_b->len)
            digit_b = num_b->arr[i];

        int sum = digit_a + digit_b + rank;

        result->arr[i] = sum % 10;
        rank = sum / 10;
    }

    result->len = max_len;

    if (rank > 0)
    {
        result->arr[result->len] = rank;
        ++result->len;
    }
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

    int num;
    scanf("%d", &num);

    LongNum first_num = {1, {1}};
    LongNum second_num = {1, {1}};
    LongNum next_num;

    for (int i = 3; i <= num; ++i)
    {
        add_struct(&next_num, &first_num, &second_num);

        first_num = second_num;
        second_num = next_num;
    }

    print_result(&second_num);

    return 0;
}