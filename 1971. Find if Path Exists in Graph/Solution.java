import java.util.stream.IntStream;

class Solution {
    private int findRoot(int[] tree, int x) {
        if (tree[x] == x) {
            return x;
        }
        tree[x] = findRoot(tree, tree[x]);
        return tree[x];
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        int[] tree = IntStream.range(0, n).toArray();
        for (int[] edge : edges) {
            int root1 = findRoot(tree, edge[0]), root2 = findRoot(tree, edge[1]);
            if (root1 != root2) {
                tree[root2] = root1;
            }
        }
        return findRoot(tree, source) == findRoot(tree, destination);
    }
}
