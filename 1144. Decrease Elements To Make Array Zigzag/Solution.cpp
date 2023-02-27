#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums)
    {
        int s[2] = { 0 }, n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = i ? nums[i - 1] : INT_MAX;
            int right = i < n - 1 ? nums[i + 1] : INT_MAX;
            s[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }
        return min(s[0], s[1]);
    }
};
