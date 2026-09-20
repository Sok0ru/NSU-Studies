#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int start, end, count;
    scanf("%d %d %d", &start, &end, &count);

    int diff = end - start;
    int step = diff / (count - 1);
    int threshold = diff / count;
}