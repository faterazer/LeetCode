import java.util.PriorityQueue;

class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(A.length);
        for (int x : A) {
            pq.add(x);
        }
        for (int i = 0; i < K; i++) {
            pq.add(-pq.poll());
        }
        return pq.stream().mapToInt(i -> i).sum();
    }
}
