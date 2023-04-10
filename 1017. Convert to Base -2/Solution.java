class Solution {
    public String baseNeg2(int n) {
        StringBuilder res = new StringBuilder();
        while (n != 0) {
            res.append(n & 1);
            n = -(n >> 1);
        }
        return res.length() > 0 ? res.reverse().toString() : "0";
    }
}
