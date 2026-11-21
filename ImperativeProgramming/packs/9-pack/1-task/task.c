#include <stdio.h>

typedef struct Node
{
    int key;
    char value[8];
} Node;

void bubble_sort(Node arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j].key > arr[j + 1].key)
            {
                Node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count_nodes;
    scanf("%d", &count_nodes);

    Node node[count_nodes];

    for (int i = 0; i < count_nodes; ++i)
        scanf("%d %7s", &node[i].key, node[i].value);

    bubble_sort(node, count_nodes);

    for (int i = 0; i < count_nodes; ++i)
        printf("%d %s\n", node[i].key, node[i].value);

    return 0;
}