class Solution {
    public String reverseStr(String s, int k) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i += 2 * k) {
            reverse(arr, i, Math.min(i + k, arr.length) - 1);
        }
        return new String(arr);
    }

    private void reverse(char[] arr, int left, int right) {
        char temp;
        while (left < right) {
            temp = arr[left];
            arr[left++] = arr[right];
            arr[right--] = temp;
        }
    }
}
