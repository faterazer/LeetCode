#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums)
    {
        auto binary_reflection = [](int x) -> int {
            int result = 0;
            while (x) {
                result = (result << 1) | (x & 1);
                x >>= 1;
            }
            return result;
        };
        ranges::sort(nums, {}, [&](int x) { return pair(binary_reflection(x), x); });
        return nums;
    }
};
