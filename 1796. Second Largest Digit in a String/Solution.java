class Solution {
    public int secondHighest(String s) {
        int digit = 0, count = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                digit |= 1 << (c - '0');
            }
        }
        for (int i = 9; i >= 0; i--) {
            if ((digit & (1 << i)) != 0 && ++count == 2) {
                return i;
            }
        }
        return -1;
    }
}
