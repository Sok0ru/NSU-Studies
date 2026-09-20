#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int total_bits;
    scanf("%d", &total_bits);

    while (total_bits > 0)
    {
        int byte = 0;
        int bits_in_byte;

        if (total_bits >= 8)
            bits_in_byte = 8;
        else
            bits_in_byte = total_bits;

        for (int bit = 0; bit < bits_in_byte; ++bit)
        {
            int bit_value;
            scanf("%1d", &bit_value);

            byte |= bit_value << bit;
        }
        printf("%d ", byte);
        total_bits -= bits_in_byte;
    }

    return 0;
}