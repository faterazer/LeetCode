#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums)
    {
        for (size_t i = 1; i < nums.size(); i++)
            if ((nums[i - 1] & 1) == (nums[i] & 1))
                return false;
        return true;
    }
};
