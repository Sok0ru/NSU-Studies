#include <stdio.h>

int main()
{
    int a, b;
    int count = 2;
    float avg;

    scanf("%d", &a);
    scanf("%d", &b);

    avg = (a + b) / count;

    printf("%d\n", a / b);
    printf("%.2f ", avg);
    return 0;
}