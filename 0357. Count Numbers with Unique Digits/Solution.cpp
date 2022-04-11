class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int res = 10, tmp = 9;
        for (int i = 2, j = 9; i <= n; ++i, --j) {
            res += tmp * j;
            tmp *= j;
        }
        return res;
    }
};
