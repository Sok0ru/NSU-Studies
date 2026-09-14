#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    int min_val;
    int min_idx = 1;
    int max_val;
    int max_idx = 1;

    for (int i = 0; i < count; i++)
    {
        int current;
        scanf("%d", &current);
        if (i == 0 || current < min_val)
        {
            min_val = current;
            min_idx = i + 1;
        }
        if (i == 0 || current > max_val)
        {
            max_val = current;
            max_idx = i + 1;
        }
    }

    printf("%d %d %d %d", min_val, min_idx, max_val, max_idx);
    return 0;
}