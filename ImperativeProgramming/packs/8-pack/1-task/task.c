#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    char *strings[100005];

    int next_index = 0;
    int len;
    int index;

    for (int i = 0; i < count; ++i)
    {
        int request_type;
        scanf("%d", &request_type);

        switch (request_type)
        {
        case 0:
        {
            scanf("%d", &len);

            strings[next_index] = malloc((len + 1) * sizeof(char));
            scanf("%s", strings[next_index]);

            ++next_index;
            break;
        }

        case 1:
        {
            scanf("%d", &index);

            free(strings[index]);
            strings[index] = NULL;
            break;
        }

        case 2:
        {
            scanf("%d", &index);

            printf("%s\n", strings[index]);
            break;
        }

        case 3:
        {
            char symbol;
            scanf("%d %c", &index, &symbol);

            int symbol_count = 0;

            for (int j = 0; strings[index][j] != '\0'; ++j)
            {
                if (strings[index][j] == symbol)
                    ++symbol_count;
            }

            printf("%d\n", symbol_count);
            break;
        }
        }
    }

    for (int i = 0; i < next_index; ++i)
        free(strings[i]);

    return 0;
}