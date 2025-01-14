#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        return ranges::count_if(nums, [&](int x) {
            return x < k;
        });
    }
};
