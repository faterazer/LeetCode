class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int[] idx = new int[2];
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (count < 2) {
                    idx[count++] = i;
                } else {
                    return false;
                }
            }
        }
        return count == 0 || (count == 2 && s1.charAt(idx[0]) == s2.charAt(idx[1]) && s1.charAt(idx[1]) == s2.charAt(idx[0]));
    }
}
