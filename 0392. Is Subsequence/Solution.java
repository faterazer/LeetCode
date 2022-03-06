import java.util.Arrays;

class Solution {
    public boolean isSubsequence_MK1(String s, String t) {
        int si = 0;
        for (int ti = 0; si < s.length() && ti < t.length(); ++ti) {
            if (s.charAt(si) == t.charAt(ti)) {
                ++si;
            }
        }
        return si == s.length();
    }

    public boolean isSubsequence_MK2(String s, String t) {
        int tn = t.length();
        int[][] dp = new int[tn + 1][26];
        Arrays.fill(dp[tn], tn);
        for (int i = tn - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if ('a' + j == t.charAt(i)) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int ti = 0;
        for (int si = 0; si < s.length(); ++si) {
            if (dp[ti][s.charAt(si) - 'a'] == tn) {
                return false;
            } else {
                ti = dp[ti][s.charAt(si) - 'a'] + 1;
            }
        }
        return true;
    }
}
