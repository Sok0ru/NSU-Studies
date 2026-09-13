#include <stdio.h>
#include <math.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int correct_num;
    int m, p, k, l;

    scanf("%d", &correct_num);
    scanf("%d %d %d %d", &m, &p, &k, &l);

    int floor_old = (p - 1) * l + k - 1;
    int apart_floor = ceil((double)m / ((double)floor_old + 1));
    int apart_p = l * apart_floor;
    int current_p = (correct_num - 1) / apart_p + 1;
    int current_k = (correct_num - 1) % apart_p / apart_floor + 1;

    printf("%d %d", current_p, current_k);
    return 0;
}