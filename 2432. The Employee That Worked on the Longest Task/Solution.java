class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int max = -1, res = n, lastTime = 0;
        for (int[] log : logs) {
            if ((log[1] - lastTime) > max) {
                max = log[1] - lastTime;
                res = log[0];
            } else if ((log[1] - lastTime) == max && log[0] < res)
                res = log[0];
            lastTime = log[1];
        }
        return res;
    }
}
