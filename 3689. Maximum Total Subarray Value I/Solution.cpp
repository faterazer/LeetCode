#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        auto [mn, mx] = ranges::minmax(nums);
        return (mx - mn) * 1LL * k;
    }
};
