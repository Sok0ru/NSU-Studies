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

    int main_num = 0;
    while (main_num < count)
    {
        int result_count = 0;
        int following_num = main_num + 1;
        while (following_num < count)
        {
            if (nums[following_num] < nums[main_num])
            {
                ++result_count;
            }
            ++following_num;
        }
        printf("%d ", result_count);
        ++main_num;
    }

    return 0;
}