import java.util.ArrayList;
import java.util.List;

class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> buff = new ArrayList<>();

    private void dfs(int[][] graph, int source, int dest) {
        buff.add(source);
        if (source == dest) {
            res.add(new ArrayList<>(buff));
        } else {
            for (Integer neighbour : graph[source]) {
                dfs(graph, neighbour, dest);
            }
        }
        buff.remove(buff.size() - 1);
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        dfs(graph, 0, graph.length - 1);
        return res;
    }
}
