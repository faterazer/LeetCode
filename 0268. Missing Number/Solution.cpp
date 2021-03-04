#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber_MK1(vector<int> &nums); // Sort.
    int missingNumber_MK2(vector<int> &nums); // XOR
    int missingNumber_MK3(vector<int> &nums);     // Gauss' Formula
};

// Sort Approach.
// Time complexity: O(n)
// Space complexity: O(1)
int Solution::missingNumber_MK1(vector<int> &nums)
{
    size_t i = 0, n = nums.size();
    while (i < n)
    {
        if (nums[i] != i && nums[i] < n)
            swap(nums[i], nums[nums[i]]);
        else
            i++;
    }
    i = 0;
    while (i < n && nums[i] == i)
        i++;
    return i;
}

// XOR Approach
// Time complexity: O(n)
// Space complexity: O(1)
int Solution::missingNumber_MK2(vector<int> &nums)
{
    int n = nums.size();
    for (size_t i = 0; i < nums.size(); i++)
        n ^= i ^ nums[i];
    return n;
}

// Gauss' Formula
// Time Complexity: O(n)
// Space Complexity: O(1)
int Solution::missingNumber_MK3(vector<int> &nums)
{
    size_t sum = nums.size() * (nums.size() + 1) / 2;
    for (const auto &n : nums)
        sum -= n;
    return sum;
}
