import java.util.*;

class Edge {
    public int x;
    public int y;
    public int distance;

    public Edge(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.distance = d;
    }
}

class Pos {
    public int x;
    public int y;
    public int id;

    Pos(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }
}

class BIT {
    private final int[] tree;
    private final int[] idRec;

    public BIT(int n) {
        tree = new int[n];
        Arrays.fill(tree, Integer.MAX_VALUE);
        idRec = new int[n];
        Arrays.fill(idRec, -1);
    }

    public static int lowbit(int x) {
        return x & -x;
    }

    public int query(int idx) {
        int minVal = Integer.MAX_VALUE, res = -1;
        while (idx < tree.length) {
            if (tree[idx] < minVal) {
                minVal = tree[idx];
                res = idRec[idx];
            }
            idx += lowbit(idx);
        }
        return res;
    }

    public void update(int idx, int val, int id) {
        while (idx > 0) {
            if (tree[idx] > val) {
                tree[idx] = val;
                idRec[idx] = id;
            }
            idx -= lowbit(idx);
        }
    }
}

class DisjointSetUnion {
    private final int[] tree;

    public DisjointSetUnion(int n) {
        this.tree = new int[n];
        Arrays.fill(tree, -1);
    }

    private int findRoot(int e) {
        if (tree[e] == -1) {
            return e;
        } else {
            int root = findRoot(tree[e]);
            tree[e] = root;
            return root;
        }
    }

    public boolean unionSet(int x, int y) {
        int root_x = findRoot(x), root_y = findRoot(y);
        if (root_x == root_y) {
            return false;
        }
        tree[root_y] = root_x;
        return true;
    }
}

class Solution {
    private int manhattanDistance(int[] point_x, int[] point_y) {
        return Math.abs((point_x[0] - point_y[0])) + Math.abs((point_x[1] - point_y[1]));
    }

    // Kruskal
    public int minCostConnectPoints_MK1(int[][] points) {
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                edges.add(new Edge(i, j, manhattanDistance(points[i], points[j])));
            }
        }
        Collections.sort(edges, (Comparator.comparingInt(o -> o.distance)));
        DisjointSetUnion dsu = new DisjointSetUnion(points.length);
        int res = 0, count = 1;
        for (Edge edge : edges) {
            if (dsu.unionSet(edge.x, edge.y)) {
                res += edge.distance;
                ++count;
                if (count == points.length) {
                    break;
                }
            }
        }
        return res;
    }

    // Prim
    public int minCostConnectPoints_MK2(int[][] points) {
        int n = points.length;
        boolean[] inMST = new boolean[n];
        int[] minDistance = new int[n];
        Arrays.fill(minDistance, Integer.MAX_VALUE);
        minDistance[0] = 0;
        int res = 0, count = 0;
        while (count < n) {
            int curPoint = -1, curDistance = Integer.MAX_VALUE;
            for (int i = 0; i < n; ++i) {
                if (!inMST[i] && minDistance[i] < curDistance) {
                    curPoint = i;
                    curDistance = minDistance[i];
                }
            }
            inMST[curPoint] = true;
            res += curDistance;
            ++count;
            for (int i = 0; i < n; ++i) {
                if (!inMST[i]) {
                    minDistance[i] = Math.min(minDistance[i], manhattanDistance(points[curPoint], points[i]));
                }
            }
        }
        return res;
    }

    private void build(List<Pos> posList, List<Edge> edges) {
        Collections.sort(posList, (o1, o2) -> o1.x != o2.x ? o1.x - o2.x : o1.y - o2.y);
        TreeSet<Integer> idMap = new TreeSet<>();
        for (Pos pos : posList) {
            idMap.add(pos.y - pos.x);
        }
        BIT bit = new BIT(idMap.size() + 1);
        for (int i = posList.size() - 1; i >= 0; i--) {
            Pos pos = posList.get(i);
            int idx = idMap.headSet(pos.y - pos.x, true).size();
            int j = bit.query(idx);
            if (j != -1) {
                edges.add(new Edge(pos.id, posList.get(j).id, Math.abs(posList.get(j).x - pos.x) + Math.abs(posList.get(j).y - pos.y)));
            }
            bit.update(idx, pos.x + pos.y, i);
        }
    }

    private List<Edge> build_edges(int[][] points) {
        List<Pos> posList = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            posList.add(new Pos(points[i][0], points[i][1], i));
        }
        List<Edge> edges = new ArrayList<>();
        build(posList, edges);
        int temp;
        for (Pos pos : posList) {
            temp = pos.x;
            pos.x = pos.y;
            pos.y = temp;
        }
        build(posList, edges);
        for (Pos pos : posList) {
            pos.x *= -1;
        }
        build(posList, edges);
        for (Pos pos : posList) {
            temp = pos.x;
            pos.x = pos.y;
            pos.y = temp;
        }
        build(posList, edges);
        return edges;
    }

    public int minCostConnectPoints(int[][] points) {
        List<Edge> edges = build_edges(points);

        Collections.sort(edges, (Comparator.comparingInt(o -> o.distance)));
        DisjointSetUnion dsu = new DisjointSetUnion(points.length);
        int res = 0, count = 1;
        for (Edge edge : edges) {
            if (dsu.unionSet(edge.x, edge.y)) {
                res += edge.distance;
                ++count;
                if (count == points.length) {
                    break;
                }
            }
        }
        return res;
    }
}
