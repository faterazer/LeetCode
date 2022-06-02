import java.util.Random;

class Solution {
    public int repeatedNTimes_MK1(int[] A) {
        for (int i = 2; i < A.length; i++) {
            if (A[i] == A[i - 1] || A[i] == A[i - 2])
                return A[i];
        }
        return A[0];
    }

    public int repeatedNTimes_MK2(int[] A) {
        int n = A.length;
        Random random = new Random();

        for (int i = 0; i < 10; ++i) {
            int x = random.nextInt(n), y = random.nextInt(n);
            if (x != y && A[x] == A[y]) {
                return A[x];
            }
        }
        return repeatedNTimes_MK1(A);
    }
}
