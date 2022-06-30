#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        auto mid_ptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr, res = 0;
        for (const int& e : nums)
            res += abs(e - mid);
        return res;
    }
};
