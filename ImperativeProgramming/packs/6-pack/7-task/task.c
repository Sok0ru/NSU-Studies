#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    unsigned long long masks[30000];
    int curr_pairs = 0;

    for (int first = 0; first < count; ++first)
    {
        scanf("%llx", &masks[first]);

        for (int second = 0; second < first; ++second)
        {
            if ((masks[first] & masks[second]) == 0)
                ++curr_pairs;
        }
    }

    printf("%d", curr_pairs);

    return 0;
}