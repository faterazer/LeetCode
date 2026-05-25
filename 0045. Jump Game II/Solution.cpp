#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = ssize(nums), result = 0;
        int cur_end = 0, next_end = 0;
        for (int i = 0; i < n - 1; ++i) {
            next_end = max(next_end, i + nums[i]);
            if (i == cur_end) {
                cur_end = next_end;
                ++result;
            }
        }
        return result;
    }
};
