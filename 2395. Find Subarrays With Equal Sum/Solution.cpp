#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums)
    {
        unordered_set<int> seen;
        for (size_t i = 1; i < nums.size(); i++)
            if (!seen.insert(nums[i] + nums[i - 1]).second)
                return true;
        return false;
    }
};
