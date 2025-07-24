class Solution {
public:
    int countHousePlacements(int n)
    {
        int a = 1, b = 2, tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = (a + b) % MOD;
            a = b;
            b = tmp;
        }
        return 1LL * b * b % MOD;
    }

private:
    constexpr static int MOD = 1000000007;
};
