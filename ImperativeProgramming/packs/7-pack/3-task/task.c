#include <stdio.h>

typedef struct List_s
{
    int next;
    char value[8];
} List;

List lists[200001];

int first[1000001];
int last[1000001];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i <= 1000000; ++i)
        first[i] = -1;

    int entries;
    scanf("%d", &entries);

    for (int i = 0; i < entries; ++i)
    {
        int key;
        scanf("%d %7s", &key, lists[i].value);

        lists[i].next = -1;

        if (first[key] == -1)
        {
            first[key] = i;
            last[key] = i;
        }
        else
        {
            lists[last[key]].next = i;
            last[key] = i;
        }
    }

    for (int key = 0; key <= 1000000; ++key)
    {
        if (first[key] != -1)
        {
            int curr = first[key];

            while (curr != -1)
            {
                printf("%d %s\n", key, lists[curr].value);
                curr = lists[curr].next;
            }
        }
    }

    return 0;
}