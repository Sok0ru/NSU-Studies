#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;

    scanf("%d", &count);

    int nums[count];

    for (int i = 0; i < count; ++i)
    {
        int selected_num;
        scanf("%d", &selected_num);
        nums[i] = selected_num;
    }

    int step = 1;

    while (step <= count)
    {
        int result = 0;
        for (int k = step - 1; k < count; k += step)
        {
            result += nums[k];
        }

        printf("%d\n", result);

        ++step;
    }
    return 0;
}
