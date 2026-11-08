#include <stdio.h>
#include <stdint.h>

void swap_bytes(int32_t *value)
{
    uint8_t *bytes = (uint8_t *)value;

    uint8_t temp = bytes[0];
    bytes[0] = bytes[3];
    bytes[3] = temp;

    temp = bytes[1];
    bytes[1] = bytes[2];
    bytes[2] = temp;
}

int main()
{
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);

    int32_t count;
    fread(&count, sizeof(count), 1, stdin);

    int need_swap = 0;

    if (count < 1 || count > 10000)
    {
        swap_bytes(&count);
        need_swap = 1;
    }

    int32_t sum = 0;

    for (int i = 0; i < count; ++i)
    {
        int32_t value;
        fread(&value, sizeof(value), 1, stdin);

        if (need_swap)
            swap_bytes(&value);

        sum += value;
    }

    if (need_swap)
        swap_bytes(&sum);

    fwrite(&sum, sizeof(sum), 1, stdout);

    return 0;
}