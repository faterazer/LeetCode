class Solution {
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void kth_element(int[] arr, int l, int k, int r) {
        if (l >= r || k < l || k > r) {
            return;
        }
        int last = l;
        for (int i = l + 1; i <= r; i++) {
            if (arr[i] <= arr[l]) {
                swap(arr, i, ++last);
            }
        }
        swap(arr, l, last);
        if (k < last) {
            kth_element(arr, l, k, last - 1);
        } else if (k > last) {
            kth_element(arr, last + 1, k, r);
        }
    }

    private int idxMapping(int idx, int n) {
        return (2 * idx + 1) % (n | 1);
    }

    public void wiggleSort(int[] nums) {
        int n = nums.length, mid_idx = n / 2;
        kth_element(nums, 0, mid_idx, n - 1);
        int mid = nums[mid_idx];

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            int J = idxMapping(j, n);
            if (nums[J] > mid) {
                swap(nums, idxMapping(i, n), J);
                ++i;
                ++j;
            } else if (nums[J] < mid) {
                swap(nums, idxMapping(k, n), J);
                --k;
            } else {
                ++j;
            }
        }
    }
}
