import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        Map<Integer, Map<Integer, Integer>> E = new HashMap<>();
        for (int i = 0; i < n; i++) {
            E.put(i, new HashMap<>());
        }
        for (int[] edge : edges) {
            E.get(edge[0]).put(edge[1], edge[2] + 1);
            E.get(edge[1]).put(edge[0], edge[2] + 1);
        }

        Map<Integer, Integer> seen = new HashMap<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        pq.offer(new int[]{maxMoves, 0});
        while (!pq.isEmpty()) {
            int remainMoves = pq.element()[0], node = pq.element()[1];
            pq.remove();
            if (!seen.containsKey(node)) {
                seen.put(node, remainMoves);
                for (Integer neighbour : E.get(node).keySet()) {
                    if (!seen.containsKey(neighbour) && E.get(node).get(neighbour) <= remainMoves) {
                        pq.offer(new int[]{remainMoves - E.get(node).get(neighbour), neighbour});
                    }
                }
            }
        }
        int res = seen.size();
        for (int[] edge : edges) {
            int a = seen.getOrDefault(edge[0], 0);
            int b = seen.getOrDefault(edge[1], 0);
            res += Math.min(a + b, edge[2]);
        }
        return res;
    }
}
