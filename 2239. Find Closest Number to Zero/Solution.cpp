#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums)
    {
        return ranges::min(nums, [](int a, int b) -> bool {
            return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
        });
    }
};
