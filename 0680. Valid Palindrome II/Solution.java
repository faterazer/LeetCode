class Solution {
    public boolean validPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s.charAt(l) == s.charAt(r)) {
            l += 1;
            r -= 1;
        }
        return l >= r || this.isPalindrome(s, l + 1, r) || this.isPalindrome(s, l, r - 1);
    }

    private boolean isPalindrome(String s, int low, int high) {
        for (; low < high; low++, high--)
            if (s.charAt(low) != s.charAt(high))
                return false;
        return true;
    }
}
