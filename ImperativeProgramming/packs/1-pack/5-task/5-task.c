#include <stdio.h>
#include <stdlib.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    int r;
    scanf("%d %d", &a, &b);
    printf("%d", a / b - (a % b != 0 && a < 0));
    printf(" %d", a / b + (a % b != 0 && a > 0));
    printf(" %d", (a / b));

    r = a % b;
    if (r < 0)
    {
        r += abs(b);
    }
    printf(" %d", r);
    return 0;
}