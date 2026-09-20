#include <stdio.h>

int digit_value(char num)
{
    if (num >= '0' && num <= '9')
        return num - '0';

    return num - 'a' + 10;
}

int decimal_convert(char *number, int notation)
{
    int decimal = 0;

    for (int i = 0; number[i] != '\0'; i++)
        decimal = decimal * notation + digit_value(number[i]);
    return decimal;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int in_notation, out_notation;
    char num[65];

    scanf("%d %d %s", &in_notation, &out_notation, num);

    int decimal_num = decimal_convert(num, in_notation);
    char result[65];
    int length = 0;

    while (decimal_num > 0)
    {
        int digit = decimal_num % out_notation;

        if (digit < 10)
            result[length] = '0' + digit;
        else
            result[length] = 'a' + digit - 10;

        ++length;
        decimal_num /= out_notation;
    }
    for (int i = length - 1; i >= 0; --i)
    {
        printf("%c", result[i]);
    }
    return 0;
}
