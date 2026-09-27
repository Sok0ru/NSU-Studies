#include <stdio.h>
#include <math.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int hours, minutes, seconds, k;
    scanf("%d %d %d %d", &hours, &minutes, &seconds, &k);

    int total_seconds = hours * 3600 + minutes * 60 + seconds;
    total_seconds += k;

    int new_hours = total_seconds / 3600;
    int new_minutes = (total_seconds % 3600) / 60;
    int new_seconds = total_seconds % 60;

    if (new_hours >= 24)
    {
        new_hours %= 24;
    }

    printf("%d %d %d", new_hours, new_minutes, new_seconds);
    return 0;
}