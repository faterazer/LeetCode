#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> ids_map;
        for (int i = 0; i < n; i++)
            ids_map[nums[i]].emplace_back(i);

        int res = n;
        for (const auto& [_, ids] : ids_map) {
            int max_gap = n - ids.back() + ids[0];
            for (size_t i = 1; i < ids.size(); i++)
                max_gap = max(max_gap, ids[i] - ids[i - 1]);
            res = min(res, max_gap);
        }
        return res / 2;
    }
};
