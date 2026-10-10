#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds)
{
    int hours = -1;
    int minutes = -1;
    int seconds = 0;

    int time_parts = sscanf(iStr, "%d:%d:%d", &hours, &minutes, &seconds);

    if (time_parts == 1)
    {
        *oHours = -1;

        if (oMinutes != NULL)
            *oMinutes = -1;

        if (oSeconds != NULL)
            *oSeconds = -1;

        return 0;
    }

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
    {
        *oHours = -1;

        if (oMinutes != NULL)
            *oMinutes = -1;

        if (oSeconds != NULL)
            *oSeconds = -1;
        return 0;
    }

    *oHours = hours;

    if (oMinutes != NULL)
        *oMinutes = minutes;

    if (oSeconds != NULL)
    {
        if (time_parts == 3)
            *oSeconds = seconds;
        else
            *oSeconds = 0;
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char iStr[16];
    scanf("%15s", iStr);

    int oHours;
    int oMinutes;
    int oSeconds;
    int result;

    result = readTime(iStr, &oHours, &oMinutes, &oSeconds);
    printf("%d %d %d %d\n", result, oHours, oMinutes, oSeconds);

    result = readTime(iStr, &oHours, &oMinutes, NULL);
    printf("%d %d %d\n", result, oHours, oMinutes);

    result = readTime(iStr, &oHours, NULL, NULL);
    printf("%d %d\n", result, oHours);

    return 0;
}