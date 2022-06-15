#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), [](const string& left, const string& right) {
            return left.size() < right.size();
        });
        vector<int> dp(words.size(), 1);
        int i = 0, j = 0, n = words.size();
        while (j < n && words[j].size() == words.front().size())
            ++j;
        for (int k = j; k < n;) {
            while (k < n && words[k].size() == words[j].size())
                ++k;
            if (words[j].size() - words[i].size() == 1) {
                for (int a = j; a < k; ++a)
                    for (int b = i; b < j; ++b)
                        if (isChain(words[b], words[a]))
                            dp[a] = max(dp[a], dp[b] + 1);
            }
            i = j;
            j = k;
        }
        return *max_element(dp.begin(), dp.end());
    }

private:
    bool isChain(const string& a, const string& b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int an = a.size(), bn = b.size(), diff = 0;
        for (int i = 0, j = 0; i < an && j < bn;) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                ++j;
                ++diff;
            }
            if (diff > 1)
                return false;
        }
        return true;
    }
};
