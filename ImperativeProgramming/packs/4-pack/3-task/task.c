#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *concat(char *pref, const char *suff)
{
    int pref_len = strlen(pref);
    int suff_len = strlen(suff);

    for (int i = 0; i < suff_len; ++i)
        pref[pref_len + i] = suff[i];

    pref[pref_len + suff_len] = '\0';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    char *result = malloc(1);
    result[0] = '\0';

    int result_len = 0;

    for (int i = 0; i < count; ++i)
    {
        char str[101];
        scanf("%100s", str);

        int str_len = strlen(str);

        result = realloc(result, result_len + str_len + 1);
        concat(result, str);
        result_len += str_len;
    }

    printf("%s", result);

    free(result);

    return 0;
}