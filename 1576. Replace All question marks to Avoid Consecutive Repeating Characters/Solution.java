class Solution {
    public String modifyString(String s) {
        char[] res = s.toCharArray();
        char sentinel = '#', lc, rc;
        for (int i = 0; i < res.length; i++) {
            if (res[i] == '?') {
                lc = i == 0 ? sentinel : res[i - 1];
                rc = i == res.length - 1 || res[i + 1] == '?' ? sentinel : res[i + 1];
                for (res[i] = 'a'; res[i] <= 'c' && (res[i] == lc || res[i] == rc); res[i]++)
                    ;
            }
        }
        return new String(res);
    }
}
