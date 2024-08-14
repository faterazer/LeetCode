#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> last_same(nums.size());
        int last = 0;
        last_same[0] = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if ((nums[i] & 1) == (nums[i - 1] & 1))
                last = i;
            last_same[i] = last;
        }

        vector<bool> res(queries.size());
        for (size_t i = 0; i < queries.size(); i++)
            res[i] = queries[i][0] >= last_same[queries[i][1]];
        return res;
    }
};
