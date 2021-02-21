class Solution {
    public int romanToInt(String s) {
        int ans = mapping(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            int prev = mapping(s.charAt(i - 1));
            int cur = mapping(s.charAt(i));
            if (prev < cur) {
                ans -= prev * 2;
            }
            ans += cur;
        }
        return ans;
    }

    private int mapping(char c) {
        return switch (c) {
            case 'I' -> 1;
            case 'V' -> 5;
            case 'X' -> 10;
            case 'L' -> 50;
            case 'C' -> 100;
            case 'D' -> 500;
            case 'M' -> 1000;
            default -> 0;
        };
    }
}
