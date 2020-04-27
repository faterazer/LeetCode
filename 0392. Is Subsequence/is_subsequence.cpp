#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t);
};

bool Solution::isSubsequence(string s, string t)
{
    size_t i = 0;
    for (size_t j = 0; i < s.size() && j < t.size(); j++)
        if (s[i] == s[j])
            i++;
    return i == s.size();
}
