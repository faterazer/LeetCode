class Solution {
    public char repeatedCharacter(String s) {
        int seen = 0;
        for (int i = 0; i < s.length(); i++) {
            int offset = s.charAt(i) - 'a';
            if ((seen & (1 << offset)) != 0) {
                return s.charAt(i);
            }
            seen |= 1 << offset;
        }
        return 0;
    }
}
