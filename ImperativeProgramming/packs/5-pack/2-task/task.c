#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sinus(double num_x)
{
    double sin = num_x;
    double sum = num_x;

    for (int i = 1; i < 100; ++i)
    {
        sin *= -num_x * num_x / (2 * i * (2 * i + 1));
        sum += sin;

        if (sin < 1e-16 && sin > -1e-16)
            break;
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        double num_x;
        scanf("%lf", &num_x);

        printf("%0.15lf\n", sinus(num_x));
    }

    return 0;
}