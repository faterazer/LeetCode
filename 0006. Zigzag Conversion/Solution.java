class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        char[] res = new char[s.length()];
        int tp = 0;
        for (int i = 0, a = 2 * numRows - 2, b = 0; i < numRows; i++, a -= 2, b += 2) {
            int j = i;
            res[tp++] = s.charAt(j);
            while (j < s.length()) {
                if (a > 0 && j + a < s.length()) {
                    res[tp++] = s.charAt(j + a);
                }
                j += a;
                if (b > 0 && j + b < s.length()) {
                    res[tp++] += s.charAt(j + b);
                }
                j += b;
            }
        }
        return new String(res);
    }
}
