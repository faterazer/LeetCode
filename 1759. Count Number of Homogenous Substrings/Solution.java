class Solution {
    public int countHomogenous(String s) {
        int P = (int) (1e9 + 7), res = 0, count = 0;
        char lastC = 0;
        for (int i = 0; i < s.length(); i++) {
            count = s.charAt(i) == lastC ? count + 1 : 1;
            res = (res + count) % P;
            lastC = s.charAt(i);
        }
        return res;
    }
}
