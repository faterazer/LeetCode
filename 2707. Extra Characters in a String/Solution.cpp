#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary)
    {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size() + 1, 0);
        for (size_t i = 0; i < s.size(); i++) {
            dp[i + 1] = dp[i] + 1;
            for (int j = i; j >= 0; j--)
                if (dict.contains(s.substr(j, i - j + 1)))
                    dp[i + 1] = min(dp[i + 1], dp[j]);
        }
        return dp.back();
    }
};
