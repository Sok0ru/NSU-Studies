#include <stdio.h>
#include <stdint.h>

typedef struct
{
    int len;
    unsigned char bits[64];
} Encode;

Encode encode_symbol[10000];

int main()
{
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);

    int count;
    fread(&count, sizeof(count), 1, stdin);

    for (int i = 0; i < count; ++i)
    {
        int len;
        fread(&len, sizeof(len), 1, stdin);

        encode_symbol[i].len = len;
        fread(encode_symbol[i].bits, 1, len, stdin);
    }

    int text_len;
    fread(&text_len, sizeof(text_len), 1, stdin);

    unsigned char byte = 0;
    int bit_next = 0;

    for (int i = 0; i < text_len; ++i)
    {
        uint16_t symbol;
        fread(&symbol, sizeof(symbol), 1, stdin);

        for (int j = 0; j < encode_symbol[symbol].len; ++j)
        {
            if (encode_symbol[symbol].bits[j] == 1)
                byte |= 1 << bit_next;

            ++bit_next;

            if (bit_next == 8)
            {
                fwrite(&byte, 1, 1, stdout);

                byte = 0;
                bit_next = 0;
            }
        }
    }

    if (bit_next > 0)
        fwrite(&byte, 1, 1, stdout);

    return 0;
}