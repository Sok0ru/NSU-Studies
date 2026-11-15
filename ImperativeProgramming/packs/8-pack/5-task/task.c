#include <stdio.h>

int bin_search(int arr[], int size, long long x)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}

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

    for (int i = 0; i < requests; ++i)
    {
        long long x;
        scanf("%lld", &x);

        int position = bin_search(unit_a, size, x);
        int answer;

        if (position == 0)
            answer = 0;
        else if (position == size)
            answer = size - 1;
        else
        {
            long long dist_left = x - unit_a[position - 1];
            long long dist_right = unit_a[position] - x;

            if (dist_left < dist_right)
                answer = position - 1;
            else
                answer = position;
        }

        long long distance = unit_a[answer] - x;

        if (distance < 0)
            distance = -distance;

        printf("%d %lld\n", answer, distance);
    }

    return 0;
}