#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tokens_s
{
    int num;
    char **arr;
} Tokens;

int is_delims(char symbol, const char *delims)
{
    for (int i = 0; delims[i] != '\0'; ++i)
    {
        if (symbol == delims[i])
            return 1;
    }

    return 0;
}

void tokensSplit(Tokens *tokens, const char *str, const char *delims)
{
    int start_index = 0;
    int word_count = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; ++i)
    {
        if (str[i] == '\0' || is_delims(str[i], delims))
        {
            if (i > start_index)
            {
                if (tokens->arr != NULL)
                {
                    int word_len = i - start_index;
                    tokens->arr[word_count] = malloc((word_len + 1) * sizeof(char));

                    for (int j = 0; j < word_len; ++j)
                        tokens->arr[word_count][j] = str[start_index + j];

                    tokens->arr[word_count][word_len] = '\0';
                }
                ++word_count;
            }
            start_index = i + 1;
        }
    }

    tokens->num = word_count;
}

void tokensFree(Tokens *tokens)
{
    if (tokens->arr != NULL)
    {
        for (int i = 0; i < tokens->num; ++i)
            free(tokens->arr[i]);

        free(tokens->arr);
    }

    tokens->arr = NULL;
    tokens->num = 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char *str = malloc(1000002 * sizeof(char));
    fgets(str, 1000002, stdin);

    int len = strlen(str);

    while (str[len - 1] == '\n' || str[len - 1] == '\r')
    {
        str[len - 1] = '\0';
        --len;
    }

    Tokens tokens;
    tokens.num = 0;
    tokens.arr = NULL;

    tokensSplit(&tokens, str, ".,;:");

    int words = tokens.num;

    if (words > 0)
    {
        tokens.arr = malloc(words * sizeof(char *));
        tokensSplit(&tokens, str, ".,;:");
    }

    printf("%d\n", tokens.num);

    for (int i = 0; i < tokens.num; ++i)
        printf("%s\n", tokens.arr[i]);

    tokensFree(&tokens);
    free(str);

    return 0;
}