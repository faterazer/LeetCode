#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long long cnt1 = 0, cnt2 = 0, res = 0;
        for (char c : text) {
            if (c == pattern[1]) {
                ++cnt2;
                res += cnt1;
            }
            if (c == pattern[0])
                ++cnt1;
        }
        return res + max(cnt1, cnt2);
    }
};
