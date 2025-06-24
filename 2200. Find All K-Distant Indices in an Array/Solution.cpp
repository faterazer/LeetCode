#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (nums[i] != key)
                continue;
            j = max(j, i - k);
            while (j < n && j <= i + k)
                ans.emplace_back(j++);
        }
        return ans;
    }
};
