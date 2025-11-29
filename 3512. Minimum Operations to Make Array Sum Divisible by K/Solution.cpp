#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        return reduce(nums.begin(), nums.end()) % k;
    }
};
