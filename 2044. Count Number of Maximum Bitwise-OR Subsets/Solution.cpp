#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int max_or = reduce(nums.begin(), nums.end(), 0, bit_or());
        int ans = 0;

        function<void(size_t, int)> dfs = [&](size_t i, int cur_or) -> void {
            if (i == nums.size()) {
                ans += cur_or == max_or;
                return;
            }
            dfs(i + 1, cur_or | nums[i]); // Include current number
            dfs(i + 1, cur_or); // Exclude current number
        };

        dfs(0, 0);
        return ans;
    }
};
