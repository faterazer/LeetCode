class Solution {
    public boolean checkZeroOnes(String s) {
        int[] res = new int[2];
        int i = 0;
        for (int j = 1; j <= s.length(); j++) {
            if (j == s.length() || s.charAt(j) != s.charAt(i)) {
                if (s.charAt(i) == '0') {
                    res[0] = Math.max(res[0], j - i);
                } else {
                    res[1] = Math.max(res[1], j - i);
                }
                i = j;
            }
        }
        return res[1] > res[0];
    }
}
