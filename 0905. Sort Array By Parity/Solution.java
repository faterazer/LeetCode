class Solution {
    public int[] sortArrayByParity(int[] A) {
        int front = 0, rear = A.length - 1;
        while (front < rear) {
            if (A[front] % 2 == 1) {
                int tmp = A[front];
                A[front] = A[rear];
                A[rear--] = tmp;
            } else front++;
        }
        return A;
    }
}
