class Solution {
    public int balancedStringSplit(String s) {
        int cnt = 0, ans = 0;
        for (char ch : s.toCharArray()) {
            cnt += ch == 'L' ? 1 : -1;
            if (cnt == 0) {
                ans++;
            }
        }
        return ans;
    }
}
