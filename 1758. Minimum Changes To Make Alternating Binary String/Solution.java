class Solution {
    public int minOperations(String s) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) - '0' != i % 2) {
                count1++;
            } else {
                count2++;
            }
        }
        return Math.min(count1, count2);
    }
}
