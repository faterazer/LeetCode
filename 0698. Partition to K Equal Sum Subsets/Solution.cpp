#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = reduce(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;

        int target = sum / k, n = nums.size();
        ranges::sort(nums, greater<int>());

        vector<int> visited(n, 0);
        function<bool(int, int, int)> dfs = [&](int idx, int cur, int cnt) -> bool {
            if (cnt == k - 1)
                return true;
            if (cur == target)
                return dfs(cnt + 1, 0, cnt + 1);
            for (int i = idx; i < n; i++) {
                if (visited[i] || cur + nums[i] > target)
                    continue;
                visited[i] = 1;
                if (dfs(i + 1, cur + nums[i], cnt))
                    return true;
                visited[i] = 0;
                if (cur == 0)
                    break;
            }
            return false;
        };

        return dfs(0, 0, 0);
    }
};
