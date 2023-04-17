#include <string>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int left = accum_days(max(arriveAlice, arriveBob));
        int right = accum_days(min(leaveAlice, leaveBob));
        return max(right - left + 1, 0);
    }

private:
    int accum_days(const string& s)
    {
        int month = stoi(s.substr(0, 2)), day = stoi(s.substr(3));
        for (int i = 0; i < month - 1; i++)
            day += days[i];
        return day;
    }

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};
