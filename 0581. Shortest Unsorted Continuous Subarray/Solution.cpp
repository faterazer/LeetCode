#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    int findUnsortedSubarray_MK1(vector<int> &nums)
    {
        int beg = 0, n = nums.size();
        while (beg + 1 < n && nums[beg] <= nums[beg + 1])
            beg++;
        if (beg == n - 1)
            return 0;
        int end = n - 1;
        while (end - 1 >= 0 && nums[end] >= nums[end - 1])
            end--;
        int max_item = numeric_limits<int>::min(), min_item = numeric_limits<int>::max();
        for (int i = beg; i <= end; i++) {
            max_item = max(max_item, nums[i]);
            min_item = min(min_item, nums[i]);
        }
        for (beg = 0; beg < n && nums[beg] <= min_item; beg++)
            ;
        for (end = n - 1; end >= 0 && nums[end] >= max_item; end--)
            ;
        return end - beg + 1;
    }

    /**
     * More concise
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    int findUnsortedSubarray_MK2(vector<int> &nums)
    {
        int max_item = nums[0], min_item = nums.back();
        int n = nums.size(), beg = -1, end = -2;
        for (size_t i = 1; i < n; i++) {
            max_item = max(max_item, nums[i]);
            min_item = min(min_item, nums[n - 1 - i]);
            if (nums[i] < max_item)
                end = i;
            if (nums[n - 1 - i] > min_item)
                beg = n - 1 - i;
        }
        return end - beg + 1;
    }
};
