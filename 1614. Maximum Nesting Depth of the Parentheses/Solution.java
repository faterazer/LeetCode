class Solution {
    public int maxDepth(String s) {
        int lp = 0, res = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                res = Math.max(res, ++lp);
            } else if (c == ')') {
                lp--;
            }
        }
        return res;
    }
}
