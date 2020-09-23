#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        for (size_t i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};
