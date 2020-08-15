class Solution {
    public int longestPalindrome(String s) {
        int[] counter = new int[128];
        for (char ch : s.toCharArray())
            counter[ch]++;
        int ret = 0;
        for (int n : counter)
            ret += n - (n & 1);
        return ret < s.length() ? ret + 1 : ret;
    }
}
