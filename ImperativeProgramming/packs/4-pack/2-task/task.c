#include <stdio.h>
#include <string.h>

void reverse(char *start, int len)
{
    for (int i = 0; i < len / 2; ++i)
    {
        char temp = start[i];
        start[i] = start[len - 1 - i];
        start[len - 1 - i] = temp;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    char str[101];

    for (int i = 0; i < count; ++i)
    {
        scanf("%100s", str);

        int len = strlen(str);
        reverse(str, len);

        puts(str);
    }

    return 0;
}