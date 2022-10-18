class Solution {
    public int scoreOfParentheses(String s) {
        int balance = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            balance += s.charAt(i) == '(' ? 1 : -1;
            if (i > 0 && s.charAt(i) == ')' && s.charAt(i - 1) == '(') {
                res += 1 << balance;
            }
        }
        return res;
    }
}
