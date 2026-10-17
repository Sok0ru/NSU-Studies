#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double angle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y)
{
    const double pi = 3.14159265358979323846;
    double ab_x = a_x - b_x;
    double ab_y = a_y - b_y;

    double ac_x = a_x - c_x;
    double ac_y = a_y - c_y;

    double scal = ab_x * ac_x + ab_y * ac_y;
    double vector = ab_x * ac_y - ab_y * ac_x;

    if (vector < 0)
        vector = -vector;

    return atan2(vector, scal) * 180.0 / pi;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int happ;
    scanf("%d", &happ);

    double a_x, a_y;
    double b_x, b_y;
    double c_x, c_y;

    for (int i = 0; i < happ; ++i)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &a_x, &a_y, &b_x, &b_y, &c_x, &c_y);
        printf("%0.20g\n", angle(a_x, a_y, b_x, b_y, c_x, c_y));
    }

    return 0;
}