class Solution {
    public int minFlipsMonoIncr(String s) {
        int count_ones = 0, count_flips = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '1') {
                ++count_ones;
            } else {
                count_flips = Math.min(count_flips + 1, count_ones);
            }
        }
        return count_flips;
    }
}
