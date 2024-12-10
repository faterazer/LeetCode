#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int n)
    {
        vector<vector<int>> f(10, vector<int>(1, 1));
        vector<vector<int>> M {
            { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
            { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
            { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
            { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
            { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }
        };

        for (n -= 1; n; n >>= 1) {
            if (n & 1)
                f = matrixMultiply(M, f);
            M = matrixMultiply(M, M);
        }

        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + f[i][0]) % MOD;
        return ans;
    };

private:
    vector<vector<int>> matrixMultiply(const vector<vector<int>>& a, const vector<vector<int>>& b)
    {
        int I = a.size(), J = a[0].size(), K = b[0].size();
        vector<vector<int>> ans(I, vector<int>(K, 0.0));
        for (int i = 0; i < I; i++)
            for (int k = 0; k < K; k++)
                for (int j = 0; j < J; j++)
                    ans[i][k] = (ans[i][k] + 1LL * a[i][j] * b[j][k] % MOD) % MOD;
        return ans;
    }

    static constexpr int MOD = 1e9 + 7;
};
