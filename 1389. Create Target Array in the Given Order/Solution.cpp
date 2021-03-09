#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<pair<int, int>> pv(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
            pv[i] = make_pair(index[i], i);
        sort(pv.begin(), pv.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        vector<int> res(nums.size());
        for (size_t i = 0; i < pv.size(); i++)
            res[i] = nums[pv[i].second];
        return res;
    }
};
