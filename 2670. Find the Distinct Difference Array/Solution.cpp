#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums)
    {
        unordered_set<int> ust;
        vector<int> res(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); i++) {
            ust.insert(nums[i]);
            res[i] = ust.size();
        }
        ust.clear();
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] -= ust.size();
            ust.insert(nums[i]);
        }
        return res;
    }
};
