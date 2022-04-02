class Solution {
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
            return 0.0;
        if (n < 0)
            return 1 / x * myPow(1 / x, -(n + 1));
        double res = 1.0;
        for (; n; n >>= 1) {
            if (n & 1)
                res *= x;
            x *= x;
        }
        return res;
    }
};
