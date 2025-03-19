#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> cnt(nums.size() + 1, 0);
        for (int x : nums) {
            int c = cnt[x]++;
            if (c == ans.size())
                ans.emplace_back();
            ans[c].emplace_back(x);
        }
        return ans;
    }
};
