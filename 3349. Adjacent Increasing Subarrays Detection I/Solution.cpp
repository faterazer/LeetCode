#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(const vector<int>& nums, int k)
    {
        int consecutive_k_runs = 0;
        const auto n = ssize(nums);
        ptrdiff_t i = 0;
        while (i < n) {
            ptrdiff_t j = i + 1;
            while (j < n && nums[j] > nums[j - 1])
                ++j;
            if (j - i >= 2 * k)
                return true;
            else if (j - i >= k)
                ++consecutive_k_runs;
            else
                consecutive_k_runs = 0;
            if (consecutive_k_runs == 2)
                return true;
            i = j;
        }
        return false;
    }
};
