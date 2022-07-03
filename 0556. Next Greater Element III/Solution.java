class Solution {
    public int nextGreaterElement(int n) {
        char[] s = String.valueOf(n).toCharArray();
        int i = s.length - 1;
        while (i > 0 && s[i] <= s[i - 1]) {
            --i;
        }
        if (i == 0) {
            return -1;
        }
        int j = s.length - 1;
        while (s[j] <= s[i - 1]) {
            --j;
        }
        swap(s, i - 1, j);
        j = s.length - 1;
        while (i < j) {
            swap(s, i++, j--);
        }
        int res = 0;
        for (char c : s) {
            int d = c - '0';
            if (res > (Integer.MAX_VALUE - d) / 10) {
                return -1;
            }
            res = res * 10 + d;
        }
        return res;
    }

    private void swap(char[] s, int i , int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
