#include <vector>
using namespace std;

class Solution {
public:
    vector<bool>
    isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> last_same(nums.size());
        last_same[0] = 0;
        for (size_t i = 1; i < nums.size(); i++)
            last_same[i] = (nums[i] & 1) == (nums[i - 1] & 1) ? i : last_same[i - 1];

        vector<bool> res(queries.size());
        for (size_t i = 0; i < queries.size(); i++)
            res[i] = queries[i][0] >= last_same[queries[i][1]];
        return res;
    }
};
