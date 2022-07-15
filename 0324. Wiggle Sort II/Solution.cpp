#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int n = nums.size();
        int mid_idx = n / 2;
        nth_element(nums.begin(), nums.begin() + mid_idx, nums.end());
        int mid = nums[mid_idx];

        auto A = [&](int x) -> int& {
            return nums[(2 * x + 1) % (n | 1)];
        };
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                ++j;
        }
    }
};
