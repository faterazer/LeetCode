#include <string>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0, ans = 0;
        for (const char &ch : s) {
            cnt += ch == 'L' ? 1 : -1;
            ans += cnt == 0;
        }
        return ans;
    }
};
