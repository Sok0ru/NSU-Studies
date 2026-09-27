#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    int num;
    int nines = 0;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &num);

        int old_nines = 0;
        int temp = num;
        while (temp > 0)
        {
            if (temp % 10 == 9)
            {
                old_nines++;
            }
            temp /= 10;
        }
        int temp_new = num - 1;
        int new_nines = 0;
        while (temp_new > 0)
        {
            if (temp_new % 10 == 9)
            {
                new_nines++;
            }
            temp_new /= 10;
        }
        new_nines += 2;
        nines += new_nines - old_nines;
    }
    printf("%d", nines);
    return 0;
}