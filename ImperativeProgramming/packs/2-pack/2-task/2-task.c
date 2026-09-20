#include <stdio.h>

int hex_value(char color)
{
    if (color >= '0' && color <= '9')
        return color - '0';

    if (color >= 'A' && color <= 'F')
        return color - 'A' + 10;

    if (color >= 'a' && color <= 'f')
        return color - 'a' + 10;

    return -1;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char color[7];
    scanf("%6s", color);

    for (int i = 0; i < 6; ++i)
    {
        if (hex_value(color[i]) == -1)
        {
            printf("-1 -1 -1");
            return 0;
        }
    }

    int red = hex_value(color[0]) * 16 + hex_value(color[1]);
    int green = hex_value(color[2]) * 16 + hex_value(color[3]);
    int blue = hex_value(color[4]) * 16 + hex_value(color[5]);

    printf("%d %d %d", red, green, blue);
    return 0;
}