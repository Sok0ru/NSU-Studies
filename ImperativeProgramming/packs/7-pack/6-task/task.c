#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node
{
    struct Node *prev, *next;
    double value;
} Node;

double *nodes[100005];

Node *getNode(double *value)
{
    return (Node *)((char *)value - offsetof(Node, value));
}

double *initList()
{
    Node *sub_node = malloc(sizeof(Node));

    sub_node->next = sub_node;
    sub_node->prev = sub_node;

    return &sub_node->value;
}

double *getNext(double *curr)
{
    return &getNode(curr)->next->value;
}

double *getPrev(double *curr)
{
    return &getNode(curr)->prev->value;
}

double *addAfter(double *where, double newval)
{
    Node *curr = getNode(where);
    Node *new = malloc(sizeof(Node));

    new->value = newval;
    new->prev = curr;
    new->next = curr->next;

    curr->next->prev = new;
    curr->next = new;

    return &new->value;
}

double *addBefore(double *where, double newval)
{
    return addAfter(getPrev(where), newval);
}

void erase(double *what)
{
    Node *curr = getNode(what);

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    free(curr);
}

void freeList(double *sub_node)
{
    double *curr = getNext(sub_node);

    while (curr != sub_node)
    {
        double *next = getNext(curr);
        erase(curr);
        curr = next;
    }

    free(getNode(sub_node));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count_tests;
    scanf("%d", &count_tests);

    for (int test = 0; test < count_tests; ++test)
    {
        int count_oper;
        scanf("%d", &count_oper);

        double *sub_node = initList();
        double *nodes[100005];

        int next_index = 0;

        for (int i = 0; i < count_oper; ++i)
        {
            int type, index;
            scanf("%d %d", &type, &index);

            switch (type)
            {
            case 1:
            {
                double value;
                scanf("%lf", &value);

                if (index == -1)
                    nodes[next_index] = addAfter(sub_node, value);
                else
                    nodes[next_index] = addAfter(nodes[index], value);

                ++next_index;
                break;
            }

            case -1:
            {
                double value;
                scanf("%lf", &value);

                if (index == -1)
                    nodes[next_index] = addBefore(sub_node, value);
                else
                    nodes[next_index] = addBefore(nodes[index], value);

                ++next_index;
                break;
            }

            case 0:
            {
                printf("%0.3lf\n", *nodes[index]);
                erase(nodes[index]);

                nodes[index] = NULL;
                break;
            }
            }
        }

        printf("===\n");

        double *curr = getNext(sub_node);

        while (curr != sub_node)
        {
            printf("%0.3lf\n", *curr);
            curr = getNext(curr);
        }

        printf("===\n");
        freeList(sub_node);
    }
    return 0;
}