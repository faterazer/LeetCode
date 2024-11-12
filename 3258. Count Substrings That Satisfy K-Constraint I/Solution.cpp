#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int i = 0, ans = 0, n = s.size();
        int cnt[2] = { 0 };
        for (int j = 0; j < n; ++j) {
            ++cnt[s[j] - '0'];
            while (cnt[0] > k && cnt[1] > k)
                --cnt[s[i++] - '0'];
            ans += j - i + 1;
        }
        return ans;
    }
};
