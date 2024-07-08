#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {
        int left_sum = 0, right_sum = reduce(nums.begin(), nums.end(), 0);
        for (size_t i = 0; i < nums.size(); i++) {
            right_sum -= nums[i];
            if (left_sum == right_sum)
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
};
