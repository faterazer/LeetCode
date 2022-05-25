#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p)
    {
        vector<int> cnt(26, 0);
        int len = 0, n = p.size();
        for (int i = 0; i < n; ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1)
                ++len;
            else
                len = 1;
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
