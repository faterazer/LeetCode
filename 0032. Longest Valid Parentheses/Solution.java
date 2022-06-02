class Solution {
    public int longestValidParentheses(String s) {
        int left_count = 0, right_count = 0, res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++left_count;
            } else {
                ++right_count;
            }
            if (left_count < right_count) {
                left_count = right_count = 0;
            } else if (left_count == right_count) {
                res = Math.max(res, 2 * left_count);
            }
        }
        left_count = right_count = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '(') {
                ++left_count;
            } else {
                ++right_count;
            }
            if (left_count > right_count) {
                left_count = right_count = 0;
            } else if (left_count == right_count) {
                res = Math.max(res, 2 * left_count);
            }
        }
        return res;
    }
}
