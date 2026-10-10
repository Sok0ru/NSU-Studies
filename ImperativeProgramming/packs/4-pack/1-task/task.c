#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int first = *(const int *)a;
    int second = *(const int *)b;

    if (first < second)
        return -1;

    if (first > second)
        return 1;

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int first_count;
    scanf("%d", &first_count);

    int first_arr[first_count];

    for (int idx = 0; idx < first_count; ++idx)
    {
        scanf("%d", &first_arr[idx]);
    }

    int second_count;
    scanf("%d", &second_count);

    int second_arr[second_count];

    for (int idx = 0; idx < second_count; ++idx)
    {
        scanf("%d", &second_arr[idx]);
    }

    qsort(first_arr, first_count, sizeof(int), compare);
    qsort(second_arr, second_count, sizeof(int), compare);

    int result[first_count];
    int result_idx = 0;

    for (int i = 0; i < first_count; ++i)
    {
        int found = 0;

        for (int j = 0; j < second_count; ++j)
        {
            if (first_arr[i] == second_arr[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            int duplicate = 0;

            for (int k = 0; k < result_idx; ++k)
            {
                if (result[k] == first_arr[i])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0)
            {
                result[result_idx] = first_arr[i];
                ++result_idx;
            }
        }
    }

    printf("%d\n", result_idx);

    for (int i = 0; i < result_idx; ++i)
        printf("%d ", result[i]);

    return 0;
}