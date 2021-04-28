import java.util.Arrays;

class Solution {
    public int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        int[] arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i / 2] + arr[i / 2 + 1] * (i % 2);
        }
        return Arrays.stream(arr).max().getAsInt();
    }
}
