#include <stdio.h>

// double cut(double num)
// {
//     int int_num = (int)(num * 100000);
//     return int_num / 100000.0;
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    int neg = 0, zero = 0, pos = 0;
    double neg_part, zero_part, pos_part;

    for (int i = 0; i < count; ++i)
    {
        int num;
        scanf("%d", &num);

        if (num < 0)
        {
            ++neg;
        }
        else if (num == 0)
        {
            ++zero;
        }
        else
        {
            ++pos;
        }
    }

    // neg_part = cut(neg / (double)count);
    // zero_part = cut(zero / (double)count);
    // pos_part = cut(pos / (double)count);

    neg_part = neg / (double)count;
    zero_part = zero / (double)count;
    pos_part = pos / (double)count;

    printf("%.5lf %.5lf %.5lf", neg_part, zero_part, pos_part);
    return 0;
}