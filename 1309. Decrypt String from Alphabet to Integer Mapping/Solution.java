class Solution {
    public String freqAlphabets(String s) {
        char base = 'a' - 1;
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0;) {
            if (s.charAt(i) == '#') {
                sb.append((char)((s.charAt(i - 2) - '0') * 10 + s.charAt(i - 1) - '0' + base));
                i -= 3;
            } else {
                sb.append((char)(s.charAt(i) - '0' + base));
                i--;
            }
        }
        return sb.reverse().toString();
    }
}
