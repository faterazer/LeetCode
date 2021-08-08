#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    int tribonacci_MK1(int n)
    {
        if (n < 3)
            return n == 0 ? 0 : 1;
        int a = 0, b = 1, c = 1, next;
        for (int i = 3; i <= n; i++) {
            next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }

    /**
     * Time complexity: O(lgn)
     * Space complexity: O(1)
     */
    int tribonacci_MK2(int n)
    {
        vector<vector<long long>> T = {{1}, {1}, {0}};
        if (n < 2)
            return T[2 - n][0];
        vector<vector<long long>> matrix = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };
        matrix = matrixPow(matrix, n - 2);
        return multiply(matrix, T)[0][0];
    }

private:
    vector<vector<long long>> multiply(const vector<vector<long long>> &a, const vector<vector<long long>> &b)
    {
        int m = a.size(), p = b.size(), n = b[0].size();
        vector<vector<long long>> res(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < p; k++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> &mtx, int n)
    {
        int N = mtx.size();
        vector<vector<long long>> res(N, vector<long long>(N, 0));
        for (int i = 0; i < N; i++)
            res[i][i] = 1;
        while (n) {
            if (n & 1)
                res = multiply(res, mtx);
            n >>= 1;
            mtx = multiply(mtx, mtx);
        }
        return res;
    }
};
