#include <string>
using namespace std;

class Solution
{
public:
    string maximumTime(string time)
    {
        for (size_t i = 0; i < time.size(); i++) {
            if (time[i] != '?')
                continue;
            if (i == 0)
                time[i] = (time[i + 1] == '?' || time[i + 1] - '0' < 4) ? '2' : '1';
            else if (i == 1)
                time[i] = time[i - 1] == '2' ? '3' : '9';
            else if (i == 3)
                time[i] = '5';
            else
                time[i] = '9';
        }
        return time;
    }
};
