#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int ans = nums[0] ^ 1;
        for (size_t i = 1; i < nums.size(); ++i)
            ans += nums[i] ^ nums[i - 1];
        return ans;
    }
};
