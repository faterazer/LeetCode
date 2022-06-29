#include <algorithm>
#include <vector>
using namespace std;

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int n = nums.size();
        auto mid_ptr = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr;

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(j++), A(i++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                ++j;
        }
    }
};
