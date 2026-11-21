#include <stdio.h>
#include <stdint.h>

int32_t arr[500000];

void quick_sort(int32_t left, int32_t right)
{
    int i = left;
    int j = right;

    int32_t pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            ++i;

        while (arr[j] > pivot)
            --j;

        if (i <= j)
        {
            int32_t temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            ++i;
            --j;
        }
    }

    if (left < j)
        quick_sort(left, j);

    if (i < right)
        quick_sort(i, right);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int32_t count;
    fread(&count, sizeof(count), 1, stdin);

    fread(arr, sizeof(int32_t), count, stdin);

    if (count > 1)
        quick_sort(0, count - 1);

    fwrite(arr, sizeof(int32_t), count, stdout);

    return 0;
}