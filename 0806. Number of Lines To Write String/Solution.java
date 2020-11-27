class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int lines = 1, width = 0;
        for (char ch : S.toCharArray()) {
            if (width + widths[ch - 'a'] > 100) {
                width = 0;
                lines++;
            }
            width += widths[ch - 'a'];
        }
        return new int[]{lines, width};
    }
}
