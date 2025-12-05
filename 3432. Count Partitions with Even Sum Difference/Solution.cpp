#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums)
    {
        int total_sum = reduce(nums.begin(), nums.end());
        return total_sum % 2 == 1 ? 0 : nums.size() - 1;
    }
};
