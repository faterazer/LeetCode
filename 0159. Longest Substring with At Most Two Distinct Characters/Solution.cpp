#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        unordered_map<char, int> cnt;
        int lo = 0, n = s.size(), res = 0;
        for (int hi = 0; hi < n; hi++) {
            cnt[s[hi]] = hi;
            while (cnt.size() > 2) {
                if (cnt[s[lo]] == lo)
                    cnt.erase(s[lo]);
                lo++;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
