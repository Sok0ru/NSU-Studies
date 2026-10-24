#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    unsigned long long masks[count];

    for (int i = 0; i < count; ++i)
    {
        scanf("%llx", &masks[i]);
    }

    int curr_pairs = 0;

    for (int first = 0; first < count; ++first)
    {
        for (int second = first + 1; second < count; ++second)
        {
            if ((masks[first] & masks[second]) == 0)
                ++curr_pairs;
        }
    }
    printf("%d", curr_pairs);

    return 0;
}