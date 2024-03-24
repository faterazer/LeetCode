#include <ranges>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;
        ranges::sort(candidates);
        helper(candidates, 0, target, v, res);
        return res;
    }

private:
    void helper(vector<int>& s, size_t idx, int target, vector<int>& v, vector<vector<int>>& res)
    {
        if (target == 0) {
            res.push_back(v);
            return;
        }

        for (size_t i = idx; i < s.size(); i++) {
            if (s[i] > target)
                break;

            v.push_back(s[i]);
            helper(s, i, target - s[i], v, res);
            v.pop_back();
        }
    }
};
