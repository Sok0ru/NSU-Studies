#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num;
    scanf("%d", &num);
    if (num <= 1)
    {
        printf("NO");
        return 0;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}