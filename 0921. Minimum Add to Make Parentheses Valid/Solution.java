class Solution {
    public int minAddToMakeValid(String s) {
        int res = 0, left = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                ++left;
            } else if (left > 0) {
                --left;
            } else {
                ++res;
            }
        }
        return res + left;
    }
}
