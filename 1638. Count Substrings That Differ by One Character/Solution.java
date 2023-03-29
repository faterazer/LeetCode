class Solution {
    private int helper(String s, String t, int i, int j) {
        int res = 0;
        for (int pre = 0, cur = 0; i < s.length() && j < t.length(); i++, j++) {
            cur++;
            if (s.charAt(i) != t.charAt(j)) {
                pre = cur;
                cur = 0;
            }
            res += pre;
        }
        return res;
    }

    public int countSubstrings(String s, String t) {
        int res = 0;
        for (int i = 0; i < t.length(); i++) {
            res += helper(s, t, 0, i);
        }
        for (int i = 1; i < s.length(); i++) {
            res += helper(s, t, i, 0);
        }
        return res;
    }
}
