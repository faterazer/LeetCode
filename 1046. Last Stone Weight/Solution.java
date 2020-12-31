import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> Q = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones)
            Q.offer(stone);
        while (Q.size() > 1) {
            int x = Q.poll(), y = Q.poll();
            if (x != y)
                Q.offer(x - y);
        }
        return Q.isEmpty() ? 0 : Q.poll();
    }
}
