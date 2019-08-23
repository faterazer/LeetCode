#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray_MK1(vector<int> &);
    int maxSubArray_MK2(vector<int> &);
private:
    int findMaxCrossingSubarray(vector<int> &, int, int, int);
    int findMaximumSubarray(vector<int> &, int, int);
};

// Dynamic method.
// Time complexity: O(n).
int Solution::maxSubArray_MK1(vector<int> &nums)
{
    int ans = nums.front();
    if (nums.size() == 1)
        return ans;

    int tmp = ans;
    for (size_t i = 1; i != nums.size(); i++) {
        if (tmp > 0)
            tmp += nums[i];
        else
            tmp = nums[i];
        
        ans = tmp > ans ? tmp : ans;
    }
    return ans;
}

// Divide-and-conquer method
// Time complexity: O(nlgn).
int Solution::maxSubArray_MK2(vector<int> &nums)
{
    return findMaximumSubarray(nums, 0, nums.size() - 1);
}

int Solution::findMaximumSubarray(vector<int> &nums, int low, int high)
{
    if (low == high)
        return nums[low];

    int mid = low + ((high - low) >> 1);
    int left_max = findMaximumSubarray(nums, low, mid);
    int right_max = findMaximumSubarray(nums, mid + 1, high);
    int cross_max = findMaxCrossingSubarray(nums, low, mid, high);
    if (left_max >= right_max && left_max >= cross_max)
        return left_max;
    else if (right_max >= left_max && right_max >= cross_max)
        return right_max;
    else
        return cross_max;
}

int Solution::findMaxCrossingSubarray(vector<int> &nums, int low, int mid, int high)
{
    int left_max = numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += nums[i];
        if (sum >= left_max)
            left_max = sum;
    }

    int right_max = numeric_limits<int>::min();
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += nums[i];
        if (sum >= right_max)
            right_max = sum;
    }
    return left_max + right_max;
}

int main()
{
    vector<int> test = { -2 , 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << Solution().maxSubArray_MK2(test) << endl;
    return 0;
}