class Solution {
    public int smallestRangeI(int[] A, int K) {
        int smallest = A[0], biggest = A[0];
        for (int i = 1; i < A.length; i++) {
            smallest = Math.min(smallest, A[i]);
            biggest = Math.max(biggest, A[i]);
        }
        return Math.max(biggest - smallest - 2 * K, 0);
    }
}
