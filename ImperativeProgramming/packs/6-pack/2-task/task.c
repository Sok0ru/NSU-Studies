#include <stdio.h>
#include <stdint.h>

int read_symbol(uint32_t *unicode)
{
    int first = fgetc(stdin);

    if (first == EOF)
        return 0;

    int ones = 0;

    for (int mask = 0x80; first & mask; mask >>= 1)
        ++ones;

    if (ones == 1 || ones > 4)
        return -1;

    int count = ones == 0 ? 1 : ones;

    uint32_t value;

    if (count == 1)
        value = first;
    else
        value = first & ((1 << (7 - count)) - 1);

    for (int i = 1; i < count; ++i)
    {
        int byte = fgetc(stdin);

        if (byte == EOF || (byte & 0xC0) != 0x80)
            return -1;

        value = (value << 6) | (byte & 0x3F);
    }

    if (value > 0x10FFFF ||
        (value >= 0xD800 && value <= 0xDFFF) ||
        (count == 2 && value < 0x80) ||
        (count == 3 && value < 0x800) ||
        (count == 4 && value < 0x10000))
    {
        value = 0xFFFD;
    }

    *unicode = value;
    return 1;
}

void write_symbol(uint32_t unicode)
{
    fputc(unicode & 0xFF, stdout);
    fputc((unicode >> 8) & 0xFF, stdout);
    fputc((unicode >> 16) & 0xFF, stdout);
    fputc((unicode >> 24) & 0xFF, stdout);
}

int main()
{
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);

    uint32_t unicode;

    while (read_symbol(&unicode) == 1)
        write_symbol(unicode);

    return 0;
}