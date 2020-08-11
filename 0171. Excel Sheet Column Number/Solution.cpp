#include <string>
using namespace std;


class Solution {
public:
    int titleToNumber(string s);
};

int Solution::titleToNumber(string s)
{
    int ans = 0;
    for (const auto &ch : s)
        ans = ans * 26 + (ch - 'A') + 1;
    return ans;
}
