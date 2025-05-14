#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<string> ans;
        int x = -1;
        for (size_t i = 0; i < groups.size(); ++i) {
            if (groups[i] != x) {
                ans.push_back(words[i]);
                x = groups[i];
            }
        }
        return ans;
    }
};
