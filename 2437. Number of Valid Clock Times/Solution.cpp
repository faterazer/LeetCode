#include <string>
using namespace std;

class Solution {
public:
    int countTime(string time)
    {
        int h_choices = 1, m_choices = 1;
        if (time[0] == '?' && time[1] == '?')
            h_choices = 24;
        else if (time[0] == '?')
            h_choices = time[1] < '4' ? 3 : 2;
        else if (time[1] == '?')
            h_choices = time[0] < '2' ? 10 : 4;

        if (time[3] == '?')
            m_choices *= 6;
        if (time[4] == '?')
            m_choices *= 10;
        return h_choices * m_choices;
    }
};
