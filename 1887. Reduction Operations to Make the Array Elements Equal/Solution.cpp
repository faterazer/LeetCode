#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0, cnt = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1])
                ++cnt;
            res += cnt;
        }
        return res;
    }
};
