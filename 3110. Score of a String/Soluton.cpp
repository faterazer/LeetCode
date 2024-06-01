#include <string>
using namespace std;

class Solution {
public:
    int scoreOfString(string s)
    {
        int res = 0;
        for (size_t i = 1; i < s.size(); i++)
            res += abs(s[i] - s[i - 1]);
        return res;
    }
};
