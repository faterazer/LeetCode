class Solution {
    private int digitSum(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    public int getLucky(String s, int k) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res += digitSum(s.charAt(i) - 'a' + 1);
        }
        for (int i = 2; i <= k; i++) {
            res = digitSum(res);
        }
        return res;
    }
}
