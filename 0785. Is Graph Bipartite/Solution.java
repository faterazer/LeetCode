import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private static final int UNCOLORED = 0;
    private static final int RED = 1;
    private static final int GREEN = 2;

    private boolean dfs(int[][] graph, int[] colors, int i, int color) {
        if (colors[i] != UNCOLORED) {
            return colors[i] == color;
        }
        colors[i] = color;
        color = color == RED ? GREEN : RED;
        for (int neighbor : graph[i]) {
            if (colors[neighbor] == UNCOLORED && !dfs(graph, colors, neighbor, color)) {
                return false;
            } else if (colors[neighbor] != color) {
                return false;
            }
        }
        return true;
    }

    public boolean isBipartite_dfs(int[][] graph) {
        int[] colors = new int[graph.length];
        Arrays.fill(colors, UNCOLORED);
        for (int i = 0; i < colors.length; i++) {
            if (colors[i] == UNCOLORED && !dfs(graph, colors, i, RED)) {
                return false;
            }
        }
        return true;
    }

    public boolean isBipartite_bfs(int[][] graph) {
        int[] colors = new int[graph.length];
        Arrays.fill(colors, UNCOLORED);
        for (int i = 0; i < colors.length; ++i) {
            if (colors[i] != UNCOLORED) {
                continue;
            }
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(i);
            colors[i] = RED;
            while (!queue.isEmpty()) {
                int vertex = queue.poll();
                int color = colors[vertex] == RED ? GREEN : RED;
                for (int neighbor : graph[vertex]) {
                    if (colors[neighbor] == UNCOLORED) {
                        colors[neighbor] = color;
                        queue.offer(neighbor);
                    } else if (colors[neighbor] != color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
