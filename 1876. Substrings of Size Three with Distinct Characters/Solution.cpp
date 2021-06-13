#include <string>
using namespace std;

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int res = 0;
        for (size_t i = 2; i < s.size(); i++)
            if (s[i - 2] != s[i - 1] && s[i - 2] != s[i] && s[i - 1] != s[i])
                res++;
        return res;
    }
};
