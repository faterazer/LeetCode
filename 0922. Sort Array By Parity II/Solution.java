class Solution {
    public int[] sortArrayByParityII(int[] A) {
        for (int i = 0, j = 1; i < A.length; i += 2) {
            if ((A[i] & 1) == 1) {
                while ((A[j] & 1) == 1)
                    j += 2;
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
}
