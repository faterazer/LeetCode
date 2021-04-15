class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        int goal = (k - 1) * m, count = 0;
        for (int i = 0; i + m < arr.length; i++) {
            if (arr[i] == arr[i + m]) {
                if (++count == goal) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
}
