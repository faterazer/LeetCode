import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (b[0] - a[0]));
        for (int i = 0; i < nums2.length; i++) {
            pq.add(new int[]{nums2[i], i});
        }
        int n = nums1.length;
        int[] res = new int[n];
        int lo = 0, hi = n - 1;
        while (!pq.isEmpty()) {
            int[] poll = pq.poll();
            if (nums1[hi] > poll[0]) {
                res[poll[1]] = nums1[hi--];
            } else {
                res[poll[1]] = nums1[lo++];
            }
        }
        return res;
    }
}
