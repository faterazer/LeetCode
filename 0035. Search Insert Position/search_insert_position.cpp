#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &, int);
};

int Solution::searchInsert(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 0)
        return -1;
    if (nums[len - 1] < target)
        return len;

    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return left;
}

int main()
{
    vector<int> array = { 1, 3, 5, 6 };
    int target1 = 5, target2 = 2, target3 = 7, target4 = 0;
    cout << Solution().searchInsert(array, target1) << endl;
    cout << Solution().searchInsert(array, target2) << endl;
    cout << Solution().searchInsert(array, target3) << endl;
    cout << Solution().searchInsert(array, target4) << endl;
    return 0;
}
