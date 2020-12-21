class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int left = 0, right = arr.length - 1, mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
}
