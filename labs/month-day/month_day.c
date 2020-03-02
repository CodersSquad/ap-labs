#include <stdio.h>
#include <stdlib.h>
/* month_day function's prototype*/
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(int argc, char **argv)
{
    int year = strtol(argv[1], NULL, 10);
    int yearday = strtol(argv[2], NULL, 10);
    int pmonth;
    int pday;

    month_day(year, yearday, &pmonth, &pday);
    char *monthString = month_name(pmonth);
    if (pmonth < 1 || pmonth > 12)
    {
        printf("%s\n", monthString);
        return 1;
    }
    printf("%s %d, %d\n", monthString, pday, year);

    return 0;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{

    int month = 1;
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    while (daytab[leap][month] < yearday)
    {
        yearday = yearday - daytab[leap][month];
        month++;
    }
    *pmonth = month;
    *pday = yearday;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

char *month_name(int n)
{

    static char *name[] = {
        "Illegal day",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};

    return (n < 1 || n > 12) ? name[0] : name[n];
}