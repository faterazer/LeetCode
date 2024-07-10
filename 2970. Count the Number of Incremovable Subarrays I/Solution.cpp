#include <vector>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums)
    {
        int i = 0, j = nums.size() - 1, n = nums.size();

        while (j && nums[j] > nums[j - 1])
            j--;
        if (j == 0)
            return (1 + n) * n / 2;

        int res = n - j + 1;
        while (i == 0 || nums[i] > nums[i - 1]) {
            while (j < n && nums[i] >= nums[j])
                j++;
            res += n - j + 1;
            i++;
        }
        return res;
    }
};

