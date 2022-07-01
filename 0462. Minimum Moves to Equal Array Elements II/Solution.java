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

    public int minMoves2(int[] nums) {
        int midIdx = nums.length / 2;
        kth_element(nums, 0, midIdx, nums.length - 1);
        int median = nums[midIdx], res = 0;
        for (int e : nums) {
            res += Math.abs(e - median);
        }
        return res;
    }
}
