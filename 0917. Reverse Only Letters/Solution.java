class Solution {
    public String reverseOnlyLetters(String S) {
        char[] s = S.toCharArray();
        int l = 0, r = S.length() - 1;
        while (l < r) {
            while (l < r && !Character.isLetter(s[l]))
                l++;
            while (l < r && !Character.isLetter(s[r]))
                r--;
            if (l < r) {
                char tmp = s[l];
                s[l++] = s[r];
                s[r--] = tmp;
            }
        }
        return String.valueOf(s);
    }
}
