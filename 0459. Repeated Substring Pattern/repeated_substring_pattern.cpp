#include <string>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s);
};

bool Solution::repeatedSubstringPattern(string s)
{
    return (s + s).find(s, 1) != s.size();
}
