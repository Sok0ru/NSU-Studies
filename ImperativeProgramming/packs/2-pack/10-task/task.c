#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count, valid, imaginary;

    scanf("%d", &count);
    scanf("%d %d", &valid, &imaginary);

    char result[60];
    int len = 0;

    if (valid == 0 && imaginary == 0)
    {
        printf("0");
        return 0;
    }

    while ((valid != 0 || imaginary != 0) && len < count)
    {
        int bit_num = (valid - imaginary) % 2;

        if (bit_num < 0)
            bit_num += 2;

        result[len] = '0' + bit_num;
        ++len;

        int valid_new = (imaginary - valid + bit_num) / 2;
        int imaginary_new = (bit_num - valid - imaginary) / 2;

        valid = valid_new;
        imaginary = imaginary_new;
    }

    for (int i = len - 1; i >= 0; --i)
    {
        printf("%c", result[i]);
    }

    return 0;
}