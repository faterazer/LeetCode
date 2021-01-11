#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    void merge_MK1(vector<int>& nums1, int m, vector<int>& nums2, int n);   // 合并后排序
    void merge_MK2(vector<int>& nums1, int m, vector<int>& nums2, int n);   // 双指针 / 从前往后
    void merge_MK3(vector<int>& nums1, int m, vector<int>& nums2, int n);   // 双指针 / 从后往前
};

void Solution::merge_MK1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i != n; i++)
        nums1[m + i] = nums2[i];
    sort(nums1.begin(), nums1.end());
}

void Solution::merge_MK2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums1_copy(nums1);
    int i = 0, j = 0, k = 0;
    while (j < m && k < n) {
        if (nums1_copy[j] <= nums2[k])
            nums1[i++] = nums1_copy[j++];
        else
            nums1[i++] = nums2[k++];
    }
    while (j < m)
        nums1[i++] = nums1_copy[j++];
    while (k < n)
        nums1[i++] = nums2[k++];
}

void Solution::merge_MK3(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}
