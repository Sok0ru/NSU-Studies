#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    int nums[20];
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &nums[i]);
    }

    int min_val = nums[0];
    int min_idx = 1;
    int max_val = nums[0];
    int max_idx = 1;

    for (int i = 1; i < count; i++)
    {
        if (nums[i] < min_val)
        {
            min_val = nums[i];
            min_idx = i + 1;
        }
        if (nums[i] > max_val)
        {
            max_val = nums[i];
            max_idx = i + 1;
        }
    }

    printf("%d %d %d %d", min_val, min_idx, max_val, max_idx);
    return 0;
}