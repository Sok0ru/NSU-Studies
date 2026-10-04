#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("0");
        return 0;
    }

    int bottom_heights[count];
    int left = 0;
    int right = count - 1;
    int max_left = 0;
    int max_right = 0;

    long long water_filling = 0;

    for (int i = 0; i < count; ++i)
        scanf("%d", &bottom_heights[i]);

    while (left <= right)
    {
        switch (bottom_heights[left] <= bottom_heights[right] ? 1 : 2)
        {
        case 1:
            if (bottom_heights[left] > max_left)
                max_left = bottom_heights[left];
            else
                water_filling += max_left - bottom_heights[left];

            ++left;
            break;

        case 2:
            if (bottom_heights[right] > max_right)
                max_right = bottom_heights[right];
            else
                water_filling += max_right - bottom_heights[right];

            --right;
            break;

        default:
            break;
        }
    }
    printf("%lld", water_filling);
    return 0;
}