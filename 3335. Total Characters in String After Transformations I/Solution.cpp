#include <string>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) // 可以用快速幂算法，空间换时间
    {
        int cnt[27] = { 0 }, P = 1e9 + 7;
        for (char c : s)
            ++cnt[c - 'a'];

        for (int i = 0; i < t; ++i) {
            for (int j = 26; j > 0; --j)
                cnt[j] = cnt[j - 1];
            cnt[0] = cnt[26];
            cnt[1] = (cnt[1] + cnt[26] % P) % P;
            cnt[26] = 0;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
            ans = (ans + cnt[i]) % P;
        return ans;
    }
};
