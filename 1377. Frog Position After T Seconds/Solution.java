import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        List<Integer>[] tree = new ArrayList[n + 1];
        Arrays.setAll(tree, e -> new ArrayList<>());
        tree[1].add(0);
        for (int[] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        double choices = dfs(tree, 0, 1, target, t);
        return choices != 0 ? 1.0 / choices : 0;
    }

    private int dfs(List<Integer>[] tree, int parent, int vertice, int target, int t) {
        if (t == 0) {
            return vertice == target ? 1 : 0;
        }
        if (vertice == target) {
            return tree[vertice].size() == 1 ? 1 : 0;
        }
        for (Integer neighbour : tree[vertice]) {
            if (neighbour != parent) {
                int choices = dfs(tree, vertice, neighbour, target, t - 1);
                if (choices != 0) {
                    return choices * (tree[vertice].size() - 1);
                }
            }
        }
        return 0;
    }
}
