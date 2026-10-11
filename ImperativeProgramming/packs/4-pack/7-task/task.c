#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char words[100][101];

    int word_count = 0;
    int symbol_count = 0;
    int prefix_len[100];
    int symbol;

    while ((symbol = getchar()) != EOF)
    {
        switch (symbol)
        {
        case ' ':
            if (symbol_count > 0)
            {
                words[word_count][symbol_count] = '\0';
                ++word_count;
                symbol_count = 0;
            }
            break;

        case '\n':
            if (symbol_count > 0)
            {
                words[word_count][symbol_count] = '\0';
                ++word_count;
                symbol_count = 0;
            }
            break;

        case '\r':
            break;

        default:
            if (symbol_count < 100)
            {
                words[word_count][symbol_count] = symbol;
                ++symbol_count;
            }
            break;
        }
    }

    if (symbol_count > 0 && word_count < 100)
    {
        words[word_count][symbol_count] = '\0';
        ++word_count;
    }

    for (int i = 0; i < word_count; ++i)
    {
        int len = strlen(words[i]);
        prefix_len[i] = len;

        for (int prefix = 1; prefix <= len; ++prefix)
        {
            int unique_prefix = 1;

            for (int j = 0; j < word_count; ++j)
            {
                if (i == j)
                    continue;

                if (strlen(words[j]) >= prefix && strncmp(words[i], words[j], prefix) == 0)
                {
                    unique_prefix = 0;
                    break;
                }
            }

            if (unique_prefix == 1)
            {
                prefix_len[i] = prefix;
                break;
            }
        }
    }

    for (int i = word_count - 1; i >= 0; --i)
    {
        for (int j = 0; j < prefix_len[i]; ++j)
            putchar(words[i][j]);

        if (i > 0)
            putchar('#');
    }

    return 0;
}