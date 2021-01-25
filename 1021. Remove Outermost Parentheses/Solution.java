class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder sb = new StringBuilder();
        int left = 0;
        for (char ch : S.toCharArray()) {
            if (ch == '(' && left++ > 0) {
                sb.append(ch);
            } else if (ch == ')' && left-- > 1) {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
