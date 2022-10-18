class Solution {
    public String countAndSay(int n) {
        String res = "1";
        for (int i = 2; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            int last = 0, j = 0;
            while (j < res.length()) {
                while (j < res.length() && res.charAt(j) == res.charAt(last)) {
                    ++j;
                }
                sb.append(j - last).append(res.charAt(last));
                last = j;
            }
            res = sb.toString();
        }
        return res;
    }
}
