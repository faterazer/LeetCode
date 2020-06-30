class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder ret = new StringBuilder();
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) != '-') {
                if (ret.length() % (K + 1) == K)
                    ret.append('-');
                ret.append(S.charAt(i));
            }
        }
        return ret.reverse().toString().toUpperCase();
    }
}
