class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] buff = new int[N + 1];
        for (int[] p : trust) {
            buff[p[0]]--;
            buff[p[1]]++;
        }
        for (int i = 1; i < buff.length; i++) {
            if (buff[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
}
