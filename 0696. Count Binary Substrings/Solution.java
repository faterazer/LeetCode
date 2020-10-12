class Solution {
    public int countBinarySubstrings(String s) {
        int prev = 0, cur = 1, ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(prev, cur);
                prev = cur;
                cur = 0;
            }
            cur += 1;
        }
        return ans + Math.min(prev, cur);
    }
}