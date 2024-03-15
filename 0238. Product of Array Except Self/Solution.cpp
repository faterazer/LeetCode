#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res(nums.size(), 1);
        int n = nums.size();
        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] * nums[i - 1];

        int suf = 1;
        for (int i = n - 2; i >= 0; i--) {
            res[i] *= suf * nums[i + 1];
            suf *= nums[i + 1];
        }
        return res;
    }
};
