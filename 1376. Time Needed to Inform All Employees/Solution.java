class Solution {
    private int dfs(int i, int[] manager, int[] informTime) {
        if (manager[i] != -1) {
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }
        return informTime[i];
    }

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = Math.max(res, dfs(i, manager, informTime));
        }
        return res;
    }
}
