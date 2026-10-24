#include <stdio.h>
#include <string.h>

int skip_marks(char symbol)
{
    return symbol == '.' || symbol == ',' ||
           symbol == ';' || symbol == ':';
}

int upper_count(char *word)
{
    int count = 0;

    for (int i = 0; word[i] != '\0'; ++i)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            ++count;
    }

    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char str[1000002];

    fgets(str, sizeof(str), stdin);

    int start = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; ++i)
    {
        if (skip_marks(str[i]) || str[i] == '\n' || str[i] == '\0')
        {
            if (i > start)
            {
                str[i] = '\0';

                char *word = &str[start];

                printf("%d/%d %s\n",
                       upper_count(word),
                       i - start,
                       word);
            }

            start = i + 1;
        }
    }

    return 0;
}