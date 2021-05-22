class Solution {
    public int maxRepeating(String sequence, String word) {
        int res = 0, n = sequence.length(), m = word.length();
        int[] next = new int[m * 2];
        for (int i = 1, j = 0; i < next.length; i++) {
            while (j > 0 && word.charAt(i % m) != word.charAt(j % m)) {
                j = next[j - 1];
            }
            if (word.charAt(i % m) == word.charAt(j % m)) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (sequence.charAt(i) != word.charAt(j % m)) {
                if (j > next.length) {
                    j = j % m + m;
                }
                while (j > 0 && sequence.charAt(i) != word.charAt(j % m)) {
                    j = next[j - 1];
                }
            }
            if (sequence.charAt(i) == word.charAt(j % m)) {
                j++;
            }
            res = Math.max(res, j / m);
        }
        return res;
    }
}
