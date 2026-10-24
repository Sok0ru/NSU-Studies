#include <stdio.h>

typedef union DoubleBits
{
    double d;
    long long bits;

} DoubleBits;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        int P, Q;
        long long mask;

        scanf("%d/%d xor %llx", &P, &Q, &mask);

        DoubleBits value;

        value.d = (double)P / Q;
        value.bits ^= mask;

        printf("%.15g\n", value.d);
    }

    return 0;
}