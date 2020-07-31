#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (size_t i = 0; i < s.size(); i += k << 1)
            reverse(s.begin() + i, i + k < s.size() ? s.begin() + i + k : s.end());
        return s;
    }
};
