#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node
{
    struct Node *prev, *next;
    double value;
} Node;

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

double *addAfter(double *where, double value)
{
    Node *curr = getNode(where);
    Node *new = malloc(sizeof(Node));

    new->value = value;
    new->prev = curr;
    new->next = curr->next;

    curr->next->prev = new;
    curr->next = new;

    return &new->value;
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

    int count, step;
    scanf("%d %d", &count, &step);

    double *sub_node = initList();
    double *last = sub_node;

    for (int i = 1; i <= count; ++i)
        last = addAfter(last, i);

    double *curr = getNext(sub_node);

    for (int not_comp = count; not_comp > 0; --not_comp)
    {
        for (int j = 1; j < step; ++j)
        {
            curr = getNext(curr);

            if (curr == sub_node)
                curr = getNext(curr);
        }

        printf("%0.0lf\n", *curr);

        if (not_comp == 1)
        {
            erase(curr);
            break;
        }

        double *next = getNext(curr);

        if (next == sub_node)
            next = getNext(next);

        erase(curr);
        curr = next;
    }

    freeList(sub_node);

    return 0;
}