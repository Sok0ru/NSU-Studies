#include <stdio.h>

int main()
{
    int num;

    if (scanf("%d", &num))
        ;
    int result = num * (num + 1) / 2;
    printf("%d\n", result);
    return 0;
}