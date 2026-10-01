#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    int num;
    scanf("%d", &num);

    int total_sum = num;

    int curr_l = 0;

    int best_sum = num;
    int best_l = 0;
    int best_r = 0;

    for (int i = 1; i < count; ++i)
    {
        int num;
        scanf("%d", &num);

        total_sum += num;

        if (total_sum < num)
        {
            total_sum = num;
            curr_l = i;
        }

        if (total_sum > best_sum)
        {
            best_sum = total_sum;
            best_l = curr_l;
            best_r = i;
        }
    }

    printf("%d %d %d", best_l, best_r, best_sum);

    return 0;
}