class Solution {
    public String reformat(String s) {
        int n1 = 0, n2 = 0;
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                n1++;
            } else {
                n2++;
            }
        }
        if (Math.abs(n1 - n2) > 1) {
            return "";
        }
        char[] res = new char[s.length()];
        if (n1 > n2) {
            n1 = 0;
            n2 = 1;
        } else {
            n1 = 1;
            n2 = 0;
        }
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                res[n1] = c;
                n1 += 2;
            } else {
                res[n2] = c;
                n2 += 2;
            }
        }
        return new String(res);
    }
}
