#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums)
    {
        int pre_sum = 0, total = reduce(nums.begin(), nums.end(), 0), ans = 0;
        for (int x : nums) {
            if (x)
                pre_sum += x;
            else if (pre_sum * 2 == total)
                ans += 2;
            else if (abs(pre_sum * 2 - total) == 1)
                ans += 1;
        }
        return ans;
    }
};
