#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        int window_size = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] - nums[i - 1] == 1)
                ++window_size;
            else
                window_size = 1;
            if (window_size >= k)
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};
