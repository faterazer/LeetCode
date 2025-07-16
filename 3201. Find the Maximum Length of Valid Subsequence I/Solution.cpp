#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        int a = 0, b = 0, c = 1, i = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] & 1)
                ++a;
            else
                ++b;
            if ((nums[i] & 1) != (nums[j] & 1)) {
                ++c;
                i = j;
            }
        }
        return ranges::max({ a, b, c });
    }
};
