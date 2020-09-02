import java.util.Arrays;

class Solution {
    public String largestTimeFromDigits(int[] A) {
        Arrays.sort(A);
        for (int i = 0; i < A.length / 2; i++) {
            int t = A[i];
            A[i] = A[A.length - 1 - i];
            A[A.length - 1 - i] = t;
        }
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                for (int k = 0; k < A.length; k++) {
                    if (i == j || i == k || j == k)
                        continue;
                    if ((A[i] < 2 || (A[i] == 2 && A[j] < 4)) && A[k] < 6)
                        return "" + A[i] + A[j] + ":" + A[k] + A[6 - i - j - k];
                }
            }
        }
        return "";
    }
}
