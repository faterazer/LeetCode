#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums)
    {
        int res = 0, s = 0;
        for (size_t i = 0; i < nums.size(); i++)
            s += i & 1 ? -nums[i] : nums[i];
        for (size_t i = 0; i < nums.size(); i++) {
            s += i & 1 ? nums[i] : -nums[i];
            res += s == 0;
            s += i & 1 ? nums[i] : -nums[i];
        }
        return res;
    }
};
