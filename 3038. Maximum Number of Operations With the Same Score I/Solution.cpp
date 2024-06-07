#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums)
    {
        int s = nums[0] + nums[1], res = 1;
        for (size_t i = 2; i + 1 < nums.size() && nums[i] + nums[i + 1] == s; i += 2)
            res++;
        return res;
    }
};
