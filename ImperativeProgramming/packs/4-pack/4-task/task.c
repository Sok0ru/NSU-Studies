#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    *oDigitsCnt = 0;

    int len = strlen(iStr);

    for (int i = 0; i < len; ++i)
    {
        if (iStr[i] >= 'a' && iStr[i] <= 'z')
            ++(*oLowerCnt);

        else if (iStr[i] >= 'A' && iStr[i] <= 'Z')
            ++(*oUpperCnt);

        else if (iStr[i] >= '0' && iStr[i] <= '9')
            ++(*oDigitsCnt);
    }

    return len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char iStr[102];
    int line = 1;

    while (fgets(iStr, sizeof(iStr), stdin) != NULL)
    {
        int len = strlen(iStr);

        if (len > 0 && iStr[len - 1] == '\n')
            iStr[len - 1] = '\0';

        int lowerCnt;
        int upperCnt;
        int digitsCnt;

        int strLen = calcLetters(iStr, &lowerCnt, &upperCnt, &digitsCnt);

        printf(
            "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
            line,
            strLen,
            lowerCnt + upperCnt,
            lowerCnt,
            upperCnt,
            digitsCnt);

        ++line;
    }

    return 0;
}