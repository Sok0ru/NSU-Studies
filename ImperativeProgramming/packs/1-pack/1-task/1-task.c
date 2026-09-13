#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    int sum = 0;
    int odd;

    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &odd))
        {
            if (odd % 2 != 0)
            {
                sum += odd;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
