#include <numeric>
#include <string>
using namespace std;

class Solution
{
public:
    int dayOfYear(string date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));
        return accumulate(begin(dayOfMonth), begin(dayOfMonth) + month, 0) + day + (month > 2 && isLeapYear(year));
    }

private:
    bool isLeapYear(int year)
    {
        return (!(year % 4) && (year % 100)) || !(year % 400);
    }

    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};
