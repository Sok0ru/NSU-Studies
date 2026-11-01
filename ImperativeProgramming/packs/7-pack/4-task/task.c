#include <stdio.h>

typedef struct List_s
{
    int value;
    int next;
    int prev;
} List;

List lists[200005];

void print_list(int first)
{
    int curr = first;

    while (curr != -1)
    {
        printf("%d\n", lists[curr].value);
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

    for (int test = 0; test < count; ++test)
    {
        int node_unit, first, last, operations;
        scanf("%d %d %d %d", &node_unit, &first, &last, &operations);

        for (int i = 0; i < node_unit; ++i)
            scanf("%d %d %d", &lists[i].value, &lists[i].next, &lists[i].prev);

        int next_index = node_unit;

        for (int i = 0; i < operations; ++i)
        {
            int type, index;
            scanf("%d %d", &type, &index);

            switch (type)
            {
            case 1:
            {
                scanf("%d", &lists[next_index].value);

                if (index == -1)
                {
                    lists[next_index].prev = -1;
                    lists[next_index].next = first;

                    if (first != -1)
                        lists[first].prev = next_index;
                    else
                        last = next_index;

                    first = next_index;
                }
                else
                {
                    lists[next_index].prev = index;
                    lists[next_index].next = lists[index].next;

                    if (lists[index].next != -1)
                        lists[lists[index].next].prev = next_index;
                    else
                        last = next_index;

                    lists[index].next = next_index;
                }

                printf("%d\n", next_index);
                ++next_index;
                break;
            }

            case -1:
            {
                scanf("%d", &lists[next_index].value);

                if (index == -1)
                {
                    lists[next_index].next = -1;
                    lists[next_index].prev = last;

                    if (last != -1)
                        lists[last].next = next_index;
                    else
                        first = next_index;

                    last = next_index;
                }
                else
                {
                    lists[next_index].next = index;
                    lists[next_index].prev = lists[index].prev;

                    if (lists[index].prev != -1)
                        lists[lists[index].prev].next = next_index;
                    else
                        first = next_index;

                    lists[index].prev = next_index;
                }

                printf("%d\n", next_index);
                ++next_index;
                break;
            }

            case 0:
            {
                int deleted = index;

                if (lists[deleted].prev != -1)
                    lists[lists[deleted].prev].next = lists[deleted].next;
                else
                    first = lists[deleted].next;

                if (lists[deleted].next != -1)
                    lists[lists[deleted].next].prev = lists[deleted].prev;
                else
                    last = lists[deleted].prev;

                printf("%d\n", lists[deleted].value);
                break;
            }
            }
        }

        printf("===\n");
        print_list(first);
    }

    return 0;
}