import java.util.Arrays;

class Solution {
    public boolean makesquare(int[] matchsticks) {
        int allLen = Arrays.stream(matchsticks).sum();
        if (allLen % 4 != 0) {
            return false;
        }
        int sideLen = allLen / 4;
        for (int matchstick : matchsticks) {
            if (matchstick > sideLen) {
                return false;
            }
        }
        Arrays.sort(matchsticks);
        for (int i = 0, j = matchsticks.length - 1; i < j; i++, j--) {
            int temp = matchsticks[i];
            matchsticks[i] = matchsticks[j];
            matchsticks[j] = temp;
        }
        return dfs(matchsticks, 0, 0, sideLen, 4, 0);
    }

    private boolean dfs(int[] matchsticks, int idx, int cur, int sideLen, int remain, int state) {
        if (remain == 0) {
            return true;
        }
        if (cur == sideLen) {
            return dfs(matchsticks, 0, 0, sideLen, remain - 1, state);
        }
        for (int i = idx; i < matchsticks.length; i++) {
            if ((state & (1 << i)) != 0) {
                continue;
            }
            if (cur + matchsticks[i] > sideLen) {
                continue;
            }
            if (dfs(matchsticks, idx + 1, cur + matchsticks[i], sideLen, remain, state | (1 << i))) {
                return true;
            }
            while (i < matchsticks.length - 1 && matchsticks[i] == matchsticks[i + 1]) {
                ++i;
            }
        }
        return false;
    }
}
