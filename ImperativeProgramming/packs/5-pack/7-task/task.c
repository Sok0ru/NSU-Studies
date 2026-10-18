#include <stdio.h>
#include <string.h>

typedef struct
{
    double p;
    double s;
    double l;
} Asimptotic;

void read_asimptotic(char *str, Asimptotic *value)
{
    value->p = 1.0;
    value->s = 0.0;
    value->l = 0.0;

    char *part = strtok(str, " \r\n");

    while (part != NULL)
    {
        if (strncmp(part, "logN", 4) == 0)
        {
            if (strchr(part, '^') != NULL)
                sscanf(part, "logN^%lf", &value->l);
            else
                value->l = 1.0;
        }

        else if (part[0] == 'N')
        {
            if (strchr(part, '^') != NULL)
                sscanf(part, "N^%lf", &value->s);
            else
                value->s = 1.0;
        }

        else if (strstr(part, "^N") != NULL)
        {
            sscanf(part, "%lf^N", &value->p);
        }

        part = strtok(NULL, " \r\n");
    }
}

int compare_asimptotics(const Asimptotic *first, const Asimptotic *second)
{
    if (first->p != second->p)
        return first->p < second->p ? -1 : 1;

    if (first->s != second->s)
        return first->s < second->s ? -1 : 1;

    if (first->l != second->l)
        return first->l < second->l ? -1 : 1;

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char count_in[102];
    fgets(count_in, sizeof(count_in), stdin);

    int count;
    sscanf(count_in, "%d", &count);

    // int count;
    // scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        char first_in[102];
        char second_in[102];

        fgets(first_in, sizeof(first_in), stdin);
        fgets(second_in, sizeof(second_in), stdin);

        Asimptotic first;
        Asimptotic second;

        read_asimptotic(first_in, &first);
        read_asimptotic(second_in, &second);

        printf("%d\n", compare_asimptotics(&first, &second));
    }

    return 0;
}