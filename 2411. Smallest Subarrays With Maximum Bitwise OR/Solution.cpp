#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    // LogTrick
    vector<int> smallestSubarrays_MK1(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; --j) {
                nums[j] |= nums[i];
                ans[j] = i - j + 1;
            }
        }
        return ans;
    }

    // 滑动窗口 + 栈
    vector<int> smallestSubarrays_MK2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left_or = 0, bottom = n - 2, right = n - 1;
        for (int left = n - 2; left >= 0; --left) {
            left_or |= nums[left];
            while (right > left && (left_or | nums[right]) == (left_or | nums[right - 1])) {
                --right;
                if (bottom >= right) {
                    for (int i = left + 1; i <= right; ++i)
                        nums[i] |= nums[i - 1];
                    bottom = left;
                    left_or = 0;
                }
            }
            ans[left] = right - left + 1;
        }
        return ans;
    }
};
