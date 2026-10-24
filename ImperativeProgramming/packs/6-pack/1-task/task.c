#include <stdio.h>

void swap_bytes(int *value)
{
    unsigned char *bytes = (unsigned char *)value;

    unsigned char temp = bytes[0];
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

    int count;
    fread(&count, sizeof(int), 1, stdin);

    int need_swap = 0;

    if (count < 1 || count > 10000)
    {
        swap_bytes(&count);
        need_swap = 1;
    }

    int sum = 0;

    for (int i = 0; i < count; ++i)
    {
        int value;
        fread(&value, sizeof(int), 1, stdin);

        if (need_swap)
            swap_bytes(&value);

        sum += value;
    }

    if (need_swap)
        swap_bytes(&sum);

    fwrite(&sum, sizeof(int), 1, stdout);

    return 0;
}