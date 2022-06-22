import java.util.Arrays;

class Solution {
    private int[] expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            --left;
            ++right;
        }
        return new int[]{left + 1, right - 1};
    }

    public String longestPalindrome_MK1(String s) {
        int begin = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            int[] span = expandAroundCenter(s, i, i);
            if (span[1] - span[0] > end - begin) {
                begin = span[0];
                end = span[1];
            }
            span = expandAroundCenter(s, i, i + 1);
            if (span[1] - span[0] > end - begin) {
                begin = span[0];
                end = span[1];
            }
        }
        return s.substring(begin, end + 1);
    }

    public String longestPalindrome_MK2(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            sb.append('#');
            sb.append(s.charAt(i));
        }
        sb.append('#');
        String ss = sb.toString();

        int[] p = new int[ss.length()];
        Arrays.fill(p, 0);
        int center = 0, maxRight = 0;
        for (int i = 1; i < ss.length(); ++i) {
            if (i >= maxRight) {
                center = i;
                maxRight = expandAroundCenter(ss, i, i)[1];
                p[i] = maxRight - center;
            } else {
                p[i] = Math.min(p[2 * center - i], maxRight - i);
                int[] span = expandAroundCenter(ss, i - p[i], i + p[i]);
                if (span[1] > maxRight) {
                    center = i;
                    maxRight = span[1];
                }
                p[i] = span[1] - i;
            }
        }

        int maxVal = p[0], maxIdx = 0;
        for (int i = 1; i < p.length; ++i) {
            if (p[i] > maxVal) {
                maxVal = p[i];
                maxIdx = i;
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = maxIdx - maxVal; i <= maxIdx + maxVal; ++i) {
            if (ss.charAt(i) != '#') {
                res.append(ss.charAt(i));
            }
        }
        return res.toString();
    }
}
