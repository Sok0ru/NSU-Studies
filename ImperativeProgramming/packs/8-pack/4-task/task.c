#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    char pattern[] = "GGGGCC";
    int prefix[] = {0, 1, 2, 3, 0, 0};

    int found = 0;
    int repeats = 0;
    int read_count = 0;

    while (read_count < count)
    {
        int symbol = getchar();

        if (symbol == EOF)
            break;

        if (symbol == '\n' || symbol == '\r')
            continue;

        ++read_count;

        while (found > 0 && symbol != pattern[found])
            found = prefix[found - 1];

        if (symbol == pattern[found])
            ++found;

        if (found == 6)
        {
            ++repeats;

            if (repeats > 30)
            {
                printf("Pathogenic");
                return 0;
            }

            found = prefix[5];
        }
    }

    printf("Non-pathogenic");
    return 0;
}