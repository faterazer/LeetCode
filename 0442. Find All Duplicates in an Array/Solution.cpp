#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                res.emplace_back(idx + 1);
            else
                nums[idx] *= -1;
        }
        return res;
    }
};
