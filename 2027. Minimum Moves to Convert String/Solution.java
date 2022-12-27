class Solution {
    public int minimumMoves(String s) {
        int i = 0, res = 0;
        while (i < s.length()) {
            if (s.charAt(i) == 'O') {
                ++i;
            } else {
                i += 3;
                ++res;
            }
        }
        return res;
    }
}
