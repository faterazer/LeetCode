import java.util.*;

class Solution {
    private int cross(int[] p, int[] q, int[] r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    private int distance(int[] p, int[] q) {
        return (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]);
    }

    public int[][] outerTrees_Jarvis(int[][] trees) {
        if (trees.length < 4) {
            return trees;
        }
        int leftMost = 0;
        for (int i = 1; i < trees.length; ++i) {
            if (trees[i][0] < trees[leftMost][0] || (trees[i][0] == trees[leftMost][0] && trees[i][1] < trees[leftMost][1])) {
                leftMost = i;
            }
        }

        int p = leftMost;
        Set<Integer> visited = new HashSet<>();
        List<int[]> res = new ArrayList<>();
        do {
            int q = (p + 1) % trees.length;
            for (int r = 0; r < trees.length; ++r) {
                if (cross(trees[p], trees[q], trees[r]) < 0) {
                    q = r;
                }
            }
            for (int i = 0; i < trees.length; ++i) {
                if (visited.contains(i) || i == p || i == q) {
                    continue;
                }
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    visited.add(i);
                    res.add(trees[i]);
                }
            }
            if (!visited.contains(q)) {
                visited.add(q);
                res.add(trees[q]);
            }
            p = q;
        } while (p != leftMost);
        return res.toArray(new int[][]{});
    }

    public int[][] outerTrees_Graham(int[][] trees) {
        if (trees.length < 4) {
            return trees;
        }
        int leftMost = 0;
        for (int i = 1; i < trees.length; ++i) {
            if (trees[i][0] < trees[leftMost][0] || (trees[i][0] == trees[leftMost][0] && trees[i][1] < trees[leftMost][1])) {
                leftMost = i;
            }
        }
        int[] temp = trees[0];
        trees[0] = trees[leftMost];
        trees[leftMost] = temp;
        Arrays.sort(trees, 1, trees.length, (a, b) -> {
            int c = cross(trees[0], a, b);
            return c == 0 ? distance(trees[0], a) - distance(trees[0], b) : -c;
        });
        int r = trees.length - 2;
        while (r > 0 && cross(trees[0], trees[trees.length - 1], trees[r]) == 0) {
            --r;
        }
        for (int i = r + 1, j = trees.length - 1; i < j; ++i, --j) {
            temp = trees[i];
            trees[i] = trees[j];
            trees[j] = temp;
        }

        Deque<Integer> stack = new ArrayDeque<>();
        stack.addLast(0);
        stack.addLast(1);
        for (int i = 2; i < trees.length; ++i) {
            int top = stack.removeLast();
            while (!stack.isEmpty() && cross(trees[stack.peekLast()], trees[top], trees[i]) < 0) {
                top = stack.removeLast();
            }
            stack.addLast(top);
            stack.addLast(i);
        }

        int size = stack.size();
        int[][] res = new int[size][];
        for (int i = 0; i < size; i++) {
            res[i] = trees[stack.removeFirst()];
        }
        return res;
    }

    public int[][] outerTrees(int[][] trees) {
        if (trees.length < 4) {
            return trees;
        }
        Arrays.sort(trees, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        List<Integer> hull = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        hull.add(0);
        for (int i = 1; i < trees.length; ++i) {
            while (hull.size() > 1 && cross(trees[hull.get(hull.size() - 2)], trees[hull.get(hull.size() - 1)], trees[i]) < 0) {
                visited.remove(hull.get(hull.size() - 1));
                hull.remove(hull.size() - 1);
            }
            visited.add(i);
            hull.add(i);
        }
        for (int i = trees.length - 2; i >= 0; --i) {
            if (!visited.contains(i)) {
                while (cross(trees[hull.get(hull.size() - 2)], trees[hull.get(hull.size() - 1)], trees[i]) < 0) {
                    visited.remove(hull.get(hull.size() - 1));
                    hull.remove(hull.size() - 1);
                }
                visited.add(i);
                hull.add(i);
            }
        }

        hull.remove(hull.size() - 1);
        int[][] res = new int[hull.size()][];
        for (int i = 0; i < hull.size(); ++i) {
            res[i] = trees[hull.get(i)];
        }
        return res;
    }
}
