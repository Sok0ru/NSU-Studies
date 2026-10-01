#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    int non_repeat_nums[count];
    int repeat_counts[count];
    int nums_count = 0;

    for (int i = 0; i < count; ++i)
    {
        int num;
        scanf("%d", &num);

        int index = -1;

        for (int j = 0; j < nums_count; ++j)
        {
            if (non_repeat_nums[j] == num)
            {
                index = j;
                break;
            }
        }

        if (index != -1)
        {
            ++repeat_counts[index];
        }
        else
        {
            index = nums_count;

            for (int j = 0; j < nums_count; ++j)
            {
                if (num < non_repeat_nums[j])
                {
                    index = j;
                    break;
                }
            }
            for (int j = nums_count; j > index; --j)
            {
                non_repeat_nums[j] = non_repeat_nums[j - 1];
                repeat_counts[j] = repeat_counts[j - 1];
            }

            non_repeat_nums[index] = num;
            repeat_counts[index] = 1;

            ++nums_count;
        }
    }

    for (int i = 0; i < nums_count; ++i)
    {
        printf("%d: %d\n", non_repeat_nums[i], repeat_counts[i]);
    }

    return 0;
}