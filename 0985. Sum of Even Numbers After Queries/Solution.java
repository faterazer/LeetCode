class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] res = new int[A.length];
        int sum = 0;
        for (int x : A) {
            if (x % 2 == 0) {
                sum += x;
            }
        }
        for (int i = 0; i < queries.length; i++) {
            int val = queries[i][0], index = queries[i][1];
            if (A[index] % 2 == 0) {
                sum -= A[index];
            }
            A[index] += val;
            if (A[index] % 2 == 0) {
                sum += A[index];
            }
            res[i] = sum;
        }
        return res;
    }
}
