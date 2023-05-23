import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final int MAX = 8;
    private static final int[][] comb = new int[MAX][MAX];

    static {
        for (int i = 0; i < MAX; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
    }

    public int numTilePossibilities(String tiles) {
        Map<Character, Integer> counter = new HashMap<>();
        for (int i = 0; i < tiles.length(); i++) {
            counter.merge(tiles.charAt(i), 1, Integer::sum);
        }

        int[] f = new int[tiles.length() + 1];
        f[0] = 1;
        int n = 0;
        for (Integer count : counter.values()) {
            n += count;
            for (int i = n; i > 0; i--) {
                for (int j = 1; j <= i && j <= count; j++) {
                    f[i] += f[i - j] * comb[i][j];
                }
            }
        }
        return Arrays.stream(f).sum() - f[0];
    }
}
