class Solution {
    private boolean isExpressive(String s, String t) {
        int si = 0, ti = 0, sn = s.length(), tn = t.length();
        while (si < sn && ti < tn) {
            if (s.charAt(si) != t.charAt(ti)) {
                return false;
            }
            int sj = si + 1;
            while (sj < sn && s.charAt(sj) == s.charAt(si)) {
                ++sj;
            }
            int tj = ti + 1;
            while (tj < tn && t.charAt(tj) == t.charAt(ti)) {
                ++tj;
            }

            int s_cnt = sj - si, t_cnt = tj - ti;
            if ((t_cnt < s_cnt && s_cnt < 3) || s_cnt < t_cnt) {
                return false;
            }
            si = sj;
            ti = tj;
        }
        return si == sn && ti == tn;
    }

    public int expressiveWords(String s, String[] words) {
        int res = 0;
        for (String word : words) {
            if (isExpressive(s, word)) {
                ++res;
            }
        }
        return res;
    }
}
