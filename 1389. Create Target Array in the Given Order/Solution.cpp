#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++)
            res.insert(res.begin() + index[i], nums[i]);
        return res;
    }
};
