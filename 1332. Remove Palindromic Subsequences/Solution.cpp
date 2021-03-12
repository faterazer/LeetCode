#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (s.empty())
            return 0;
        else if (equal(s.begin(), s.end(), s.rbegin()))
            return 1;
        else
            return 2;
    }
};
