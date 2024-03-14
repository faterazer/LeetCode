#include <vector>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums)
    {
        long long res = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
            res = nums[i] <= res ? nums[i] + res : nums[i];
        return res;
    }
};
