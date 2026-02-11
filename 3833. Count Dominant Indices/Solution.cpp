#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums)
    {
        int n = nums.size(), result = 0, suf_sum = 0;
        for (int i = n - 2; i >= 0; --i) {
            suf_sum += nums[i + 1];
            if (nums[i] > suf_sum / (n - i - 1))
                ++result;
        }
        return result;
    }
};
