#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Label_s
{
    char name[16];
    int age;
} Label;

typedef struct NameStats_s
{
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    oNames->cntTotal = cnt;
    oNames->cntLong = 0;

    oAges->cntTotal = cnt;
    oAges->cntAdults = 0;
    oAges->cntKids = 0;

    for (int i = 0; i < cnt; ++i)
    {
        if (strlen(arr[i].name) > 10)
            ++oNames->cntLong;

        if (arr[i].age >= 18)
            ++oAges->cntAdults;

        else if (arr[i].age < 14)
            ++oAges->cntKids;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    scanf("%d", &count);

    Label persons[1000];

    for (int i = 0; i < count; ++i)
    {
        scanf("%s %d let", persons[i].name, &persons[i].age);
    }

    NameStats names;
    AgeStats ages;

    calcStats(persons, count, &names, &ages);

    printf("names: total = %d\n", names.cntTotal);
    printf("names: long = %d\n", names.cntLong);
    printf("ages: total = %d\n", ages.cntTotal);
    printf("ages: adult = %d\n", ages.cntAdults);
    printf("ages: kid = %d\n", ages.cntKids);
    return 0;
}