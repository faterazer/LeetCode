#include <string>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int cnt1 = 0, cnt2 = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != i % 2)
                cnt1++;
            else
                cnt2++;
        }
        return min(cnt1, cnt2);
    }
};
