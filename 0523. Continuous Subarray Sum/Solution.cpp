#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int pre_sum = 0, n = nums.size();
        unordered_map<int, int> idx_map { { 0, -1 } };
        for (int i = 0; i < n; i++) {
            pre_sum += nums[i];
            int remainder = pre_sum % k;
            auto it = idx_map.find(remainder);
            if (it != idx_map.end() && i - it->second > 1)
                return true;
            else if (it == idx_map.end())
                idx_map[remainder] = i;
        }
        return false;
    }
};
