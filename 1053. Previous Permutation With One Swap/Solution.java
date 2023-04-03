class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int i = arr.length - 1;
        while (i > 0 && arr[i] >= arr[i - 1]) {
            i--;
        }
        if (i == 0) {
            return arr;
        }
        i -= 1;
        int j = arr.length - 1;
        while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        return arr;
    }
}
