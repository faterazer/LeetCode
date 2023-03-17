#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        vector<int> res;
        for (const int& query : queries)
            res.emplace_back(upper_bound(nums.begin(), nums.end(), query) - nums.begin());
        return res;
    }
};
