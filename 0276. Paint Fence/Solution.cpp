class Solution {
public:
    int numWays(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        int last1 = k, last2 = k * k, res = 0;
        for (int i = 2; i < n; i++) {
            res = last1 * (k - 1) + last2 * (k - 1);
            last1 = last2;
            last2 = res;
        }
        return res;
    }
};
