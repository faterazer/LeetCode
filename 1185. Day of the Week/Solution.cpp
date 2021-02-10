#include <string>
using namespace std;

class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        string dayOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (month < 3) {
            month += 12;
            year--;
        }
        int c = year / 100, y = year % 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (month + 1) / 5 + day - 1) % 7;
        return dayOfWeek[(w + 7) % 7];
    }
};
