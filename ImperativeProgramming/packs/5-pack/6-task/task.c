#include <stdio.h>

typedef struct LongNum_s
{
    int len;
    int arr[3000];
} LongNum;

void factorial(LongNum *num, int mult)
{
    int rank = 0;

    for (int i = 0; i < num->len; ++i)
    {
        int result = num->arr[i] * mult + rank;

        num->arr[i] = result % 10;
        rank = result / 10;
    }

    while (rank > 0)
    {
        num->arr[num->len] = rank % 10;
        rank /= 10;
        ++num->len;
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

    LongNum result = {1, {1}};

    for (int k = 2; k <= num; ++k)
    {
        factorial(&result, k);
    }

    print_result(&result);

    return 0;
}