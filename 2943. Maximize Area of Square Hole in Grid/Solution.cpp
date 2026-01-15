#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars)
    {
        auto longestConsecutive = [](vector<int>& nums) -> int {
            ranges::sort(nums);
            int mx = 1, cnt = 1;
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[i] == nums[i - 1] + 1)
                    mx = max(mx, ++cnt);
                else
                    cnt = 1;
            }
            return mx;
        };

        int side = min(longestConsecutive(hBars), longestConsecutive(vBars)) + 1;
        return side * side;
    }
};
