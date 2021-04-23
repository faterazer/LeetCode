class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] memo = new int[26];
        int res = -1, key;
        for (int i = 0; i < s.length(); i++) {
            key = s.charAt(i) - 'a';
            if (memo[key] == 0) {
                memo[key] = i + 1;
            } else {
                res = Math.max(res, i - memo[key]);
            }
        }
        return res;
    }
}
