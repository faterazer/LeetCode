import java.util.Arrays;

class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] count = new int[26];
        int len = 0;
        for (int i = 0; i < p.length(); i++) {
            if (i != 0 && (p.charAt(i) - p.charAt(i - 1) + 26) % 26 == 1) {
                ++len;
            } else {
                len = 1;
            }
            int index = p.charAt(i) - 'a';
            count[index] = Math.max(count[index], len);
        }
        return Arrays.stream(count).sum();
    }
}
