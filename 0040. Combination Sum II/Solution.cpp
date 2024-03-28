#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        ranges::sort(candidates);
        dfs(candidates, 0, target, path, res);
        return res;
    }

private:
    void dfs(vector<int>& candidates, size_t idx, int target, vector<int>& path, vector<vector<int>>& result)
    {
        if (target == 0) {
            result.emplace_back(path);
            return;
        }

        for (size_t i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            path.emplace_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], path, result);
            path.pop_back();
        }
    }
};
