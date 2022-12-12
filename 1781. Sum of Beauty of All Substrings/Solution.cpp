#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int beautySum(string s)
    {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int cnt[26] = { 0 };
            for (int j = i; j < n; j++) {
                ++cnt[s[j] - 'a'];
                int mx = *max_element(begin(cnt), end(cnt));
                int mn = mx;
                for (const int& x : cnt)
                    if (x > 0)
                        mn = min(mn, x);
                res += mx - mn;
            }
        }
        return res;
    }
};
