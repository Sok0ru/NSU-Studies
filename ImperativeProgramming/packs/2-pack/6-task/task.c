#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int start, end, count;
    scanf("%d %d %d", &start, &end, &count);

    int result = 0;

    for (int first = start; first <= end; ++first)
    {
        int max_step = (end - first) / (count - 1);
        int min_step = (end - first) / count + 1;

        if (min_step <= max_step)
            result += max_step - min_step + 1;
    }

    printf("%d", result);

    return 0;
}