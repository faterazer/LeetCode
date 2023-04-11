import java.util.Arrays;

class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int i = 0, n = stones.length;
        int maxMoves = Math.max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - n + 2;
        int minMoves = n;
        for (int j = 0; j < n; j++) {
            while (stones[j] - stones[i] + 1 > n) {
                i++;
            }
            if (stones[j] - stones[i] + 1 == n - 1 && j - i + 1 == n - 1) {
                minMoves = Math.min(minMoves, 2);
            } else {
                minMoves = Math.min(minMoves, n - (j - i + 1));
            }
        }
        return new int[]{minMoves, maxMoves};
    }
}
