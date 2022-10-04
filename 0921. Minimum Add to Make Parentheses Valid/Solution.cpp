#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int res = 0, l = 0;
        for (const char& c : s) {
            if (c == '(')
                ++l;
            else if (l > 0)
                --l;
            else
                ++res;
        }
        return res + l;
    }
};
