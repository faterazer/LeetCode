class Solution {
    public void duplicateZeros(int[] arr) {
        int zeros = 0;
        for (int x : arr) {
            if (x == 0) {
                zeros++;
            }
        }
        for (int i = arr.length - 1; i >= 0; i--) {
            if (i + zeros < arr.length) {
                arr[i + zeros] = arr[i];
            }
            if (arr[i] == 0 && i + (--zeros) < arr.length) {
                arr[i + zeros] = arr[i];
            }
        }
    }
}
