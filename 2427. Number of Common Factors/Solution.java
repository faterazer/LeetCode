class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public int commonFactors(int a, int b) {
        int c = gcd(a, b), res = 0;
        for (int x = 1; x * x <= c; x++) {
            if (c % x == 0) {
                res++;
                if (x * x != c) {
                    res++;
                }
            }
        }
        return res;
    }
}
