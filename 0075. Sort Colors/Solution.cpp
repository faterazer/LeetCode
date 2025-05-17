#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int i = 0, k = nums.size() - 1;
        for (int j = 0; j <= k; ++j) {
            while (j >= i && j <= k && nums[j] != 1) {
                if (nums[j] == 0)
                    swap(nums[i++], nums[j]);
                else
                    swap(nums[j], nums[k--]);
            }
        }
    }
};
