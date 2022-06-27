import java.util.Arrays;

class Solution {
    private boolean isSubsequence(String A, String B) {
        // Return true is B is a sequence of A.
        int ai = 0, bi = 0;
        while (ai < A.length() && bi < B.length()) {
            if (A.charAt(ai) == B.charAt(bi)) {
                ++bi;
            }
            ++ai;
        }
        return bi == B.length();
    }

    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, (o1, o2) -> o2.length() - o1.length());
        for (int i = 0; i < strs.length; ++i) {
            int j = 0;
            for (; j < strs.length; ++j) {
                if (i == j) {
                    continue;
                }
                if (isSubsequence(strs[j], strs[i])) {
                    break;
                }
            }
            if (j == strs.length) {
                return strs[i].length();
            }
        }
        return -1;
    }
}
