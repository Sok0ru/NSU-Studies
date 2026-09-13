#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, z;
    int s = 0;
    scanf("%d %d %d", &x, &y, &z);
    if (x <= 0)
    {
        printf("%d", -1);
        return 0;
    }
    else if (y <= 0)
    {
        printf("%d", -2);
        return 0;
    }
    else if (z <= 0)
    {
        printf("%d", -3);
        return 0;
    }
    s = 2 * ((x * y) + (y * z) + (x * z));
    printf("%d", s);
    return 0;
}