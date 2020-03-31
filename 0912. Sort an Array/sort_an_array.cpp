#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray_MK1(vector<int> &nums);   // Quick Sort
    vector<int> sortArray_MK2(vector<int> &nums); // Merge Sort
    vector<int> sortArray(vector<int> &nums); // Shell Sort
private:
    void quickSort(vector<int> &nums, int left, int right);
    void mergeSort(vector<int> &nums, int left, int right);
    void merge(vector<int> &nums, int left, int mid, int right);
};

vector<int> Solution::sortArray_MK1(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

void Solution::quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int last = left;
    for (int i = left + 1; i <= right; i++)
        if (nums[i] < nums[left])
            swap(nums[++last], nums[i]);
    swap(nums[left], nums[last]);
    quickSort(nums, left, last - 1);
    quickSort(nums, last + 1, right);
}

void Solution::mergeSort(vector<int> &nums, int left, int right)
{
    if (left < right) {
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

void Solution::merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> left_vec;
    for (int i = left; i <= mid; i++)
        left_vec.emplace_back(nums[i]);
    left_vec.emplace_back(numeric_limits<int>::max());
    vector<int> right_vec;
    for (int i = mid + 1; i <= right; i++)
        right_vec.emplace_back(nums[i]);
    right_vec.emplace_back(numeric_limits<int>::max());
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (left_vec[i] <= right_vec[j]) {
            nums[k] = left_vec[i];
            i++;
        }
        else {
            nums[k] = right_vec[j];
            j++;
        }
    }
}

vector<int> Solution::sortArray_MK2(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

vector<int> Solution::sortArray(vector<int> &nums)
{
    int n = nums.size();
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; i++) {
            for (int j = i - step; j >= 0 && nums[j] > nums[j + step]; j -= step)
                swap(nums[j], nums[j + step]);
        }
    }
    return nums;
}
