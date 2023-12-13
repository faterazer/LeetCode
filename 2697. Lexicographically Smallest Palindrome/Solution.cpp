#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s)
    {
        for (size_t i = 0, j = s.size() - 1; i < j; i++, j--)
            s[i] = s[j] = min(s[i], s[j]);
        return s;
    }
};
