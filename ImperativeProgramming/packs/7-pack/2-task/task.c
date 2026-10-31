#include <stdio.h>

typedef struct List_s
{
    char value[8];
    int next;
} List;

List lists[200005];

void print_list(int first)
{
    int curr = first;

    while (curr != -1)
    {
        printf("%s\n", lists[curr].value);
        curr = lists[curr].next;
    }

    printf("===\n");
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    for (int tests = 0; tests < count; ++tests)
    {
        int node_unit, first, operations;
        scanf("%d %d %d", &node_unit, &first, &operations);

        for (int i = 0; i < node_unit; ++i)
            scanf("%7s %d", lists[i].value, &lists[i].next);

        int nextIndex = node_unit;

        for (int i = 0; i < operations; ++i)
        {
            int type, index;
            scanf("%d %d", &type, &index);

            switch (type)
            {
            case 0:
            {
                scanf("%7s", lists[nextIndex].value);

                if (index == -1)
                {
                    lists[nextIndex].next = first;
                    first = nextIndex;
                }
                else
                {
                    lists[nextIndex].next = lists[index].next;
                    lists[index].next = nextIndex;
                }

                printf("%d\n", nextIndex);
                ++nextIndex;
                break;
            }
            case 1:
            {
                int deleted;

                if (index == -1)
                {
                    deleted = first;
                    first = lists[first].next;
                }
                else
                {
                    deleted = lists[index].next;
                    lists[index].next = lists[deleted].next;
                }

                printf("%s\n", lists[deleted].value);
                break;
            }
            default:
                break;
            }
        }

        printf("===\n");
        print_list(first);
    }

    return 0;
}