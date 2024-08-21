#include <array>
using namespace std;

class Solution {
public:
    int checkRecord(int n)
    {
        matrix M = { { { { 1, 1, 0, 1, 0, 0 } },
            { { 1, 0, 1, 1, 0, 0 } },
            { { 1, 0, 0, 1, 0, 0 } },
            { { 0, 0, 0, 1, 1, 0 } },
            { { 0, 0, 0, 1, 0, 1 } },
            { { 0, 0, 0, 1, 0, 0 } } } };
        matrix FN = pow(M, n);
        int res = 0;
        for (int x : FN[0])
            res = (res + x) % MOD;
        return res;
    }

private:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int SIZE = 6;
    using matrix = array<array<int, SIZE>, SIZE>;

    matrix matmul(matrix& A, matrix& B)
    {
        matrix C {};
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                for (int k = 0; k < SIZE; k++)
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
        return C;
    }

    matrix pow(matrix a, int b)
    {
        matrix res {};
        for (int i = 0; i < SIZE; i++)
            res[i][i] = 1;
        for (; b; b >>= 1) {
            if (b & 1)
                res = matmul(res, a);
            a = matmul(a, a);
        }
        return res;
    }
};
