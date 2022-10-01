class Solution {
    public String pushDominoes(String dominoes) {
        char[] s = dominoes.toCharArray();
        char left = 'L';
        int i = 0;
        while (i < s.length) {
            int j = i;
            while (j < s.length && s[j] == '.') {
                ++j;
            }
            char right = (j < s.length ? s[j] : 'R');
            if (left == right) {
                while (i < j) {
                    s[i++] = left;
                }
            } else if (left == 'R' && right == 'L') {
                int k = j - 1;
                while (i < k) {
                    s[i++] = 'R';
                    s[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return new String(s);
    }
}
