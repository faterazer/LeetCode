class Solution {
    public int[] replaceElements(int[] arr) {
        int max = -1, tmp;
        for (int i = arr.length - 1; i >= 0; i--) {
            tmp = arr[i];
            arr[i] = max;
            max = Math.max(max, tmp);
        }
        return arr;
    }
}
