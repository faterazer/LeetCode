class Solution {
    public int maxPower(String s) {
        int ret = 1, power = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1))
                power++;
            else {
                ret = Math.max(ret, power);
                power = 1;
            }
        }
        return Math.max(ret, power);
    }
}
