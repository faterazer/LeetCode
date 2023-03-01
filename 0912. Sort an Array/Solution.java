import java.util.ArrayList;
import java.util.List;

class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void quickSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        boolean allSame = true;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] != nums[left]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            return;
        }
        int mid = left + ((right - left) >> 1);
        swap(nums, left, mid);
        int last = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < nums[left]) {
                swap(nums, i, ++last);
            }
        }
        swap(nums, left, last);
        quickSort(nums, left, last - 1);
        quickSort(nums, last + 1, right);
    }

    public int[] sortArray_MK1(int[] nums) {    // Quick Sort
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void merge(int[] nums, int left, int mid, int right) {
        List<Integer> leftBuff = new ArrayList<>();
        for (int i = left; i <= mid; i++) {
            leftBuff.add(nums[i]);
        }
        leftBuff.add(Integer.MAX_VALUE);
        List<Integer> rightBuff = new ArrayList<>();
        for (int i = mid + 1; i <= right; i++) {
            rightBuff.add(nums[i]);
        }
        rightBuff.add(Integer.MAX_VALUE);
        int i = 0, j = 0;
        for (int k = left; k <= right; k++) {
            if (leftBuff.get(i) < rightBuff.get(j)) {
                nums[k] = leftBuff.get(i++);
            } else {
                nums[k] = rightBuff.get(j++);
            }
        }
    }

    private void mergeSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    public int[] sortArray_MK2(int[] nums) {    // Merge Sort
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void maxHeapify(int[] nums, int start, int end) {
        int parent = start, child = parent * 2 + 1;
        while (child <= end) {
            if (child + 1 <= end && nums[child] < nums[child + 1]) {
                child++;
            }
            if (nums[parent] >= nums[child]) {
                return;
            } else {
                swap(nums, parent, child);
                parent = child;
                child = parent * 2 + 1;
            }
        }
    }

    public int[] sortArray_MK3(int[] nums) {    // Heap Sort
        for (int i = (nums.length - 2) / 2; i >= 0; i--) {
            maxHeapify(nums, i, nums.length - 1);
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            swap(nums, 0, i);
            maxHeapify(nums, 0, i - 1);
        }
        return nums;
    }

    public int[] sortArray_MK4(int[] nums) {    // Shell Sort
        int n = nums.length;
        for (int step = n / 2; step > 0; step /= 2) {
            for (int i = step; i < n; i++) {
                for (int j = i - step; j >= 0 && nums[j] > nums[j + step]; j -= step) {
                    swap(nums, j, j + step);
                }
            }
        }
        return nums;
    }
}
