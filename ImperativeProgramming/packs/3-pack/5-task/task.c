#include <stdio.h>

int zero_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, pairs;
    scanf("%d %d", &size, &pairs);

    int second_conn_first[301];
    int used_second[301];

    zero_arr(second_conn_first, 301);
    zero_arr(used_second, 301);

    int r_func = 1;

    for (int i = 0; i < pairs; ++i)
    {
        int X, Y;
        scanf("%d %d", &X, &Y);

        if (second_conn_first[X] == 0)
            second_conn_first[X] = Y;
        else
            r_func = 0;

        ++used_second[Y];
    }

    if (r_func == 0)
    {
        printf("0");
        return 0;
    }

    int defined = 1;
    int inject = 1;
    int surject = 1;

    for (int i = 1; i <= size; ++i)
    {
        if (second_conn_first[i] == 0)
            defined = 0;

        if (used_second[i] > 1)
            inject = 0;

        if (used_second[i] == 0)
            surject = 0;
    }

    int biject = inject && surject;

    printf("1");

    if (defined)
        printf(" 2");

    if (inject)
        printf(" 3");

    if (surject)
        printf(" 4");

    if (biject)
        printf(" 5");

    return 0;
}