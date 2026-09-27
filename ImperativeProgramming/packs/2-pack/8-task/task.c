#include <stdio.h>

int leap(int year)
{
    if (year % 400 == 0)
        return 1;

    else if (year % 4 == 0 && year % 100 != 0)
        return 1;
    return 0;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int days, months, years, k;
    scanf("%d %d %d %d", &days, &months, &years, &k);

    while (k > 0)
    {
        int days_months;

        if (months == 2)
        {
            if (leap(years))
                days_months = 29;
            else
                days_months = 28;
        }
        else if (months == 4 || months == 6 || months == 9 || months == 11)
            days_months = 30;
        else
            days_months = 31;

        ++days;

        if (days > days_months)
        {
            days = 1;
            ++months;
        }

        if (months > 12)
        {
            months = 1;
            ++years;
        }

        --k;
    }

    printf("%d %d %d", days, months, years);
    return 0;
}