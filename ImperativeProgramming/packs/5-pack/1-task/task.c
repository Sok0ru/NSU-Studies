#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double exponent(double num_x)
{
    int neg = 0;

    double sum = 1.0;
    double exp = 1.0;

    if (num_x < 0)
    {
        num_x = -num_x;
        neg = 1;
    }

    for (int i = 1; i < 200; ++i)
    {
        exp *= num_x / i;
        sum += exp;

        if (exp < 1e-16)
            break;
    }

    if (neg != 0)
        sum = 1.0 / sum;

    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int args;
    scanf("%d", &args);

    for (int i = 0; i < args; ++i)
    {
        double num_x;
        scanf("%lf", &num_x);

        printf("%.15g\n", exponent(num_x));
    }

    return 0;
}