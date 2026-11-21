#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

int main(void)
{
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);

    int32_t count;

    if (fread(&count, sizeof(count), 1, stdin) != 1)
        return 0;

    if (count > 0)
    {
        fread(nums, sizeof(int32_t), count, stdin);

        merge_sort(0, count);

        fwrite(nums, sizeof(int32_t), count, stdout);
    }

    return 0;
}