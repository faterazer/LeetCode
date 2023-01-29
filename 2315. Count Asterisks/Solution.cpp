#include <string>
using namespace std;

class Solution {
public:
    int countAsterisks(string s)
    {
        int res = 0, bars = 0;
        for (const char& c : s) {
            if (c == '*' && bars % 2 == 0)
                ++res;
            else if (c == '|')
                ++bars;
        }
        return res;
    }
};
