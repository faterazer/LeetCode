#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    res += k - j;
                    j++;
                } else
                    k--;
            }
        }
        return res;
    }
};
