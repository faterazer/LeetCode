class Solution {
    public String removeDuplicates(String S) {
        char[] res = S.toCharArray();
        int i = 0;
        for (char ch : res) {
            if (i > 0 && res[i - 1] == ch) {
                i--;
            } else {
                res[i++] = ch;
            }
        }
        return new String(res, 0, i);
    }
}
