#include <stdlib.h>

int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year)
{
    return (!(year % 4) && (year % 100)) || !(year % 400);
}

int dayOfYear(char *date)
{
    date[4] = date[7] = '\0';
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    date[4] = date[7] = '-';
    int res = day + (month > 2 && isLeapYear(year));
    for (int i = 1; i < month; i++)
        res += dayOfMonth[i];
    return res;
}
