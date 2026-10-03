#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int select_symbol;
    int length = 0;
    char last_symbol;

    while ((select_symbol = getchar()) != -1)
    {
        if (select_symbol == ' ')
        {
            if (length > 1)
                printf("%d%c", length - 2, last_symbol);

            putchar(' ');
            length = 0;
        }
        else
        {
            if (length == 0)
                putchar(select_symbol);

            last_symbol = select_symbol;
            ++length;
        }
    }

    if (length > 1)
        printf("%d%c", length - 2, last_symbol);

    return 0;
}