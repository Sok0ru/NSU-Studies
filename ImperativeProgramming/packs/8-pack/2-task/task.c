#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    scanf("%d", &size);

    int unit_a[size];

    for (int i = 0; i < size; ++i)
        scanf("%d", &unit_a[i]);

    int requests;
    scanf("%d", &requests);

    int prev = 0;

    for (int i = 0; i < requests; ++i)
    {
        long long x;
        scanf("%lld", &x);

        long long target = x + prev;
        int left = 0;
        int right = size - 1;
        int answer = -1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (unit_a[middle] == target)
            {
                answer = middle;
                left = middle + 1;
            }
            else
                unit_a[middle] < target ? (left = middle + 1) : (right = middle - 1);
        }

        printf("%d\n", answer);
        prev = answer;
    }

    return 0;
}