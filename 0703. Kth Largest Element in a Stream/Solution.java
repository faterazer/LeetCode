import java.util.PriorityQueue;

class KthLargest {
    private PriorityQueue<Integer> minHeap;
    int limit;

    public KthLargest(int k, int[] nums) {
        limit = k;
        minHeap = new PriorityQueue<>();
        for (int n : nums) {
            minHeap.offer(n);
            if (minHeap.size() > limit)
                minHeap.poll();
        }
    }

    public int add(int val) {
        minHeap.offer(val);
        if (minHeap.size() > limit)
            minHeap.poll();
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such: KthLargest
 * obj = new KthLargest(k, nums); int param_1 = obj.add(val);
 */
