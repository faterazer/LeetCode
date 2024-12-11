#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums)
    {
        auto [mn_it, mx_it] = ranges::minmax_element(nums);
        return  mn_it - mx_it + nums.size() - 1 - (mn_it > mx_it);
    }
};
