import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int sumSubarrayMins(int[] arr) {
        int P = 1000000000 + 7;
        Deque<Integer> stack = new ArrayDeque<>();
        int[] dp = new int[arr.length];
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && arr[stack.peekLast()] > arr[i]) {
                stack.removeLast();
            }
            int j = stack.isEmpty() ? -1 : stack.peekLast();
            dp[i] = (i - j) * arr[i] + (j >= 0 ? dp[j] : 0);
            res = (res + dp[i]) % P;
            stack.offerLast(i);
        }
        return res;
    }
}
