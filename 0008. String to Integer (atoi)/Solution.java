class Solution {
    public int myAtoi(String s) {
        int res = 0, sign = 1, i = 0;
        while (i < s.length() && Character.isWhitespace(s.charAt(i))) {
            i += 1;
        }
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = s.charAt(i++) == '-' ? -1 : 1;
        }
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int d = s.charAt(i++) - '0';
            if (sign == 1 && (Integer.MAX_VALUE / 10 < res || Integer.MAX_VALUE - d < res * 10)) {
                return Integer.MAX_VALUE;
            }  else if (sign == -1 && (Integer.MIN_VALUE / 10 > res || Integer.MIN_VALUE + d > res * 10)) {
                return Integer.MIN_VALUE;
            }
            res = res * 10 + d * sign;
        }
        return res;
    }
}
