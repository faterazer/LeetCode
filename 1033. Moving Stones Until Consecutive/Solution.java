import java.util.Arrays;

class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] stones = {a, b, c};
        Arrays.sort(stones);
        if (stones[2] - stones[0] == 2) {
            return new int[]{0, 0};
        }
        return new int[]{Math.min(stones[1] - stones[0], stones[2] - stones[1]) <= 2 ? 1 : 2, stones[2] - stones[0] - 2};
    }
}
