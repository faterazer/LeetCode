#include <string>
using namespace std;

class Solution
{
public:
    int daysBetweenDates(string date1, string date2)
    {
        int y1, y2, m1, m2, d1, d2;
        sscanf(date1.c_str(), "%d-%d-%d", &y1, &m1, &d1);
        sscanf(date2.c_str(), "%d-%d-%d", &y2, &m2, &d2);
        return abs(zellerDays(y1, m1, d1) - zellerDays(y2, m2, d2));
    }

private:
    int zellerDays(int year, int month, int day)
    {
        if (month < 3) {
            year--;
            month += 12;
        }
        return (year - 1) * 365 + year / 4 - year / 100 + year / 400 + (month - 1) * 28 + 13 * (month + 1) / 5 - 7 + day;
    }
};
