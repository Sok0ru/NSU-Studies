#include <stdio.h>
#include <stdint.h>

int32_t buffer[500000];
int32_t nums[500000];

void merge_sort(int left, int right)
{
    if (right - left <= 1)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(left, mid);
    merge_sort(mid, right);

    int first = left;
    int second = mid;
    int pos = left;

    while (first < mid && second < right)
    {
        if (nums[first] <= nums[second])
            buffer[pos++] = nums[first++];
        else
            buffer[pos++] = nums[second++];
    }

    while (first < mid)
        buffer[pos++] = nums[first++];

    while (second < right)
        buffer[pos++] = nums[second++];

    for (pos = left; pos < right; ++pos)
        nums[pos] = buffer[pos];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
        scanf("%d", &nums[i]);

    merge_sort(0, count);

    int result_count = 0;

    for (int i = 0; i < count; ++i)
    {
        if (result_count == 0 || nums[i] != nums[result_count - 1])
            nums[result_count++] = nums[i];
    }

    printf("%d\n", result_count);

    for (int i = 0; i < result_count; ++i)
        printf("%d\n", nums[i]);

    return 0;
}