#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation_MK1(vector<int>& nums)
    {
        int cmax = 0, n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if (cmax > nums[i + 2])
                return false;
        }
        return true;
    }

    bool isIdealPermutation_MK2(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
            if (abs(nums[i] - i) > 1)
                return false;
        return true;
    }
};
