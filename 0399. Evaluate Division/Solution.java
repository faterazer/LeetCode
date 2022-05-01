import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class UnionFind {
    private final int[] tree;
    private final double[] weight;

    public UnionFind(int n) {
        tree = new int[n];
        Arrays.fill(tree, -1);
        weight = new double[n];
        Arrays.fill(weight, 1.0);
    }

    public void union(int a, int b, double value) {
        int rootA = findRoot(a), rootB = findRoot(b);
        if (rootA != rootB) {
            tree[rootA] = rootB;
            weight[rootA] = value / weight[a] * weight[b];
        }
    }

    public double compute(int a, int b) {
        int rootA = findRoot(a), rootB = findRoot(b);
        if (rootA != rootB) {
            return -1.0;
        } else {
            return weight[a] / weight[b];
        }
    }

    private int findRoot(int x) {
        if (tree[x] == -1) {
            return x;
        }
        int root = findRoot(tree[x]);
        weight[x] *= weight[tree[x]];
        tree[x] = root;
        return root;
    }
}

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        UnionFind unionFind = new UnionFind(2 * equations.size());
        Map<String, Integer> idMap = new HashMap<>();
        int id = 0;
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            if (!idMap.containsKey(a)) {
                idMap.put(a, id++);
            }
            if (!idMap.containsKey(b)) {
                idMap.put(b, id++);
            }
            unionFind.union(idMap.get(a), idMap.get(b), values[i]);
        }

        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            Integer a = idMap.getOrDefault(queries.get(i).get(0), null);
            Integer b = idMap.getOrDefault(queries.get(i).get(1), null);
            if (a == null || b == null) {
                res[i] = -1.0;
            } else {
                res[i] = unionFind.compute(a, b);
            }
        }
        return res;
    }
}
