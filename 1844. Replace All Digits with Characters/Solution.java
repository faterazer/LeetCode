class Solution {
    public String replaceDigits(String s) {
        char[] res = s.toCharArray();
        for (int i = 1; i < res.length; i += 2) {
            res[i] += res[i - 1] - '0';
        }
        return String.valueOf(res);
    }
}
