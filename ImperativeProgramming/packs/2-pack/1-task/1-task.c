#include <stdio.h>

int compare(char *day_in, char *day_current, int count)
{
    while (count > 0)
    {
        if (*day_in != *day_current)
            return *day_in - *day_current;

        day_in++;
        day_current++;
        count--;
    }

    return 0;
}

int length(char *num)
{
    int len = 0;
    while (*num)
    {
        ++len;
        ++num;
    }
    return len;
}

int main()
{
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char search_day[11];
    scanf("%10s", search_day);

    int len = length(search_day);
    int count = 0;
    int selected_day = 0;

    for (int i = 0; i < 7; ++i)
    {
        int day_length = length(days[i]);
        if (len <= day_length && compare(search_day, days[i], len) == 0)
        {
            count++;
            selected_day = i + 1;
        }
    }

    if (count == 0)
    {
        printf("Invalid");
    }
    else if (count > 1)
    {
        printf("Ambiguous");
    }
    else
    {
        printf("%d", selected_day);
    }

    return 0;
}