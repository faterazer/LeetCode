#include <vector>
using namespace std;

class Solution 
{
public:
    int removeElement_MK1(vector<int> &, int);
    int removeElement_MK2(vector<int> &, int);
};

// 双指针法
// Approach 1: Two Pointers
int Solution::removeElement_MK1(vector<int> &nums, int val)
{
    int lasti = 0;
    for (int i = 0; i != nums.size(); i++)
        if (nums[i] != val)
            nums[lasti++] = nums[i];
    return lasti;
}

// 改进的双指针法，当要删除的元素很少时，速度更快
// Approach 2: Two Pointers - when elements to remove are rare
int Solution::removeElement_MK2(vector<int> &nums, int val)
{
    int len = nums.size();
    for (int i = 0; i < len; ) {
        if (nums[i] == val) {
            nums[i] = nums[len - 1];
            len--;
        }
        else
            i++;
    }
    return len;
}
