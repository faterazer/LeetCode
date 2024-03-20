#include <vector>
using namespace std;

class Solution {
public:
    int search_MK1(vector<int>& nums, int target)
    {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[0] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }

    int search_MK2(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0])
                left = mid + 1;
            else
                right = mid;
        }

        if (binary_search(nums.begin(), nums.begin() + left, target))
            return lower_bound(nums.begin(), nums.begin() + left, target) - nums.begin();
        if (binary_search(nums.begin() + left, nums.end(), target))
            return lower_bound(nums.begin() + left, nums.end(), target) - nums.begin();
        return -1;
    }
};
