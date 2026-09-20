#include <stdio.h>

int to_fit(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2)
{
    if (b_1 + c_1 <= a_1 && b_2 <= a_2 && c_2 <= a_2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a_1, a_2;
    int b_1, b_2;
    int c_1, c_2;

    scanf("%d %d %d %d %d %d", &a_1, &a_2, &b_1, &b_2, &c_1, &c_2);

    int A = a_1 * a_2;
    int B = b_1 * b_2;
    int C = c_1 * c_2;

    if (B + C > A)
    {
        printf("NO");
        return 0;
    }

    if (to_fit(a_1, a_2, b_1, b_2, c_1, c_2) || to_fit(a_1, a_2, b_1, b_2, c_2, c_1) ||
        to_fit(a_1, a_2, b_2, b_1, c_1, c_2) || to_fit(a_1, a_2, b_2, b_1, c_2, c_1) ||
        to_fit(a_2, a_1, b_1, b_2, c_1, c_2) || to_fit(a_2, a_1, b_1, b_2, c_2, c_1) ||
        to_fit(a_2, a_1, b_2, b_1, c_1, c_2) || to_fit(a_2, a_1, b_2, b_1, c_2, c_1))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}