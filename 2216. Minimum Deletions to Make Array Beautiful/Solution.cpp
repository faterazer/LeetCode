#include <vector>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums)
    {
        int n = nums.size();
        size_t i = 0, j = 1;
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == nums[i]) {
                ++j;
                --n;
            }
            i = j + 1;
            j += 2;
        }
        return (n & 1) ? nums.size() - n + 1 : nums.size() - n;
    }
};
