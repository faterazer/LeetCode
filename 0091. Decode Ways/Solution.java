class Solution {
    public int numDecodings(String s) {
        int a = 0, b = 1, c = 0;
        for (int i = 0; i < s.length(); i++) {
            c = 0;
            if (s.charAt(i) != '0') {
                c = b;
            }
            if (i > 0 && s.charAt(i - 1) != '0' && (s.charAt(i - 1) - '0') * 10 + (s.charAt(i) - '0') <= 26) {
                c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
}
