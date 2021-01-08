class Solution {
    public int[] diStringMatch(String S) {
        int l = 0, r = S.length(), idx = 0;
        int[] ret = new int[r + 1];
        for (char c : S.toCharArray()) {
            ret[idx++] = c == 'I' ? l++ : r--;
        }
        ret[idx] = l;
        return ret;
    }
}
