#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        int n = nums.size(), left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res(n);
        for (size_t i = 0; i < nums.size(); i++) {
            res[i] = right + nums[i] * (2 * i - n) - left;
            left += nums[i];
            right -= nums[i];
        }
        return res;
    }
};
