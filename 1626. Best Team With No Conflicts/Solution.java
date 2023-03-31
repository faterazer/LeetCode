class Solution {
    private int lowbit(int x) {
        return x & -x;
    }

    private void update(int[] tree, int idx, int val) {
        while (idx < tree.length) {
            tree[idx] = Math.max(tree[idx], val);
            idx += lowbit(idx);
        }
    }

    private int query(int[] tree, int idx) {
        int res = 0;
        while (idx > 0) {
            res = Math.max(res, tree[idx]);
            idx -= lowbit(idx);
        }
        return res;
    }

    public int bestTeamScore(int[] scores, int[] ages) {
        int n = scores.length;
        int[][] players = new int[n][2];
        for (int i = 0; i < n; i++) {
            players[i][0] = scores[i];
            players[i][1] = ages[i];
        }
        Arrays.sort(players, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);

        int[] tree = new int[1001];
        for (int[] player : players) {
            update(tree, player[1], query(tree, player[1]) + player[0]);
        }
        return query(tree, 1000);
    }
}
