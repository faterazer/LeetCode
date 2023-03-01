#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray_MK1(vector<int>& nums) // Quick Sort
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    vector<int> sortArray_MK2(vector<int>& nums) // Merge Sort
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    vector<int> sortArray_MK3(vector<int>& nums) // Heap Sort
    {
        int n = nums.size();
        for (int i = (n - 2) / 2; i >= 0; i--)
            sift_down(nums, i, n - 1);
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            sift_down(nums, 0, i - 1);
        }
        return nums;
    }

    vector<int> sortArray_MK4(vector<int>& nums) // Shell Sort
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

private:
    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;
        if (all_of(nums.begin() + left + 1, nums.begin() + right + 1, [&](const int& e) { return e == nums[left]; }))
            return;
        int mid = left + ((right - left) >> 1);
        swap(nums[left], nums[mid]);
        int pivot = nums[left], last = left;
        for (int i = left + 1; i <= right; i++)
            if (nums[i] < pivot)
                swap(nums[i], nums[++last]);
        swap(nums[left], nums[last]);
        quickSort(nums, left, last - 1);
        quickSort(nums, last + 1, right);
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left < right) {
            int mid = left + ((right - left) >> 1);
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right)
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
            } else {
                nums[k] = right_vec[j];
                j++;
            }
        }
    }

    void sift_down(vector<int>& nums, int start, int end)
    {
        int parent = start, child = start * 2 + 1;
        while (child <= end) {
            if (child + 1 <= end && nums[child] < nums[child + 1])
                child++;
            if (nums[parent] >= nums[child])
                return;
            else {
                swap(nums[parent], nums[child]);
                parent = child;
                child = parent * 2 + 1;
            }
        }
    }
};
