#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t buffer[300000];
int64_t nums[300000];

int compare(const void *a, const void *b)
{
    int64_t first = *(const int64_t *)a;
    int64_t second = *(const int64_t *)b;

    if (first < second)
        return -1;

    if (first > second)
        return 1;

    return 0;
}

// void merge_sort(int left, int right)

// {
//     if (right - left <= 1)
//         return;

//     int mid = left + (right - left) / 2;
//     merge_sort(left, mid);
//     merge_sort(mid, right);

//     int first = left;
//     int second = mid;
//     int pos = left;

//     while (first < mid && second < right)
//     {
//         if (nums[first] <= nums[second])
//             buffer[pos++] = nums[first++];
//         else
//             buffer[pos++] = nums[second++];
//     }

//     while (first < mid)
//         buffer[pos++] = nums[first++];

//     while (second < right)
//         buffer[pos++] = nums[second++];

//     for (pos = left; pos < right; ++pos)
//         nums[pos] = buffer[pos];
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
        scanf("%lld", &nums[i]);
    // merge_sort(0, count);
    qsort(nums, count, sizeof(nums[0]), compare);

    int64_t result = 0;
    for (int i = 0; i < count; ++i)
        result += nums[i] * (count - i - 1);

    printf("%lld", result);

    return 0;
}