import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int[] buff = new int[]{0};
        for (int[] row : mat) {
            buff = kSmallestPairs(buff, row, k);
        }
        return buff[k - 1];
    }

    private int[] kSmallestPairs(int[] A, int[] B, int k) {
        int m = A.length, n = B.length;
        List<Integer> res = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{A[0] + B[0], 0, 0});
        while (!pq.isEmpty() && res.size() < k) {
            int[] p = pq.remove();
            res.add(p[0]);
            int i = p[1], j = p[2];
            if (j == 0 && i + 1 < m) {
                pq.add(new int[]{A[i + 1] + B[j], i + 1, 0});
            }
            if (j + 1 < n) {
                pq.add(new int[]{A[i] + B[j + 1], i, j + 1});
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
