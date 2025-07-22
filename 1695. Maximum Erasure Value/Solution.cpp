#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        unordered_set<int> seen;
        int s = 0, ans = 0;
        for (size_t i = 0, j = 0; j < nums.size(); ++j) {
            while (seen.contains(nums[j])) {
                seen.erase(nums[i]);
                s -= nums[i++];
            }
            s += nums[j];
            seen.emplace(nums[j]);
            ans = max(ans, s);
        }
        return ans;
    }
};
