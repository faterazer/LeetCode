#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k)
    {
        int ans = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            for (size_t j = i + 1; j < nums.size(); ++j)
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ++ans;
        return ans;
    }
};
