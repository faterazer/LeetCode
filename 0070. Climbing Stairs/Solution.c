#include <memory.h>
#include <stdio.h>

// Fibonacci
int climbStairs_MK1(int n)
{
    int prev[2] = { 1, 2 };
    if (n < 3)
        return prev[n - 1];
    for (int i = 3; i <= n; i++) {
        prev[1] += prev[0];
        prev[0] = prev[1] - prev[0];
    }
    return prev[1];
}

// Binets Method
void matrix_mulipty(int m1, int n1, long long M1[][n1], int m2, int n2, long long M2[][n2], long long res[m1][n2])
{
    int m = m1;
    int n = n2;
    long long tmp_M[m][n];
    memset(tmp_M, 0, sizeof(tmp_M));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n1; k++) {
                tmp_M[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    memcpy(res, tmp_M, sizeof(tmp_M));
}

int climbStairs_MK2(int n)
{
    long long res_vec[2][1] = { { 2 }, { 1 } };
    long long matrix[2][2] = { { 1, 1 }, { 1, 0 } };
    if (n < 3)
        return res_vec[2 - n + 1][0];
    long long op_matrix[2][2] = { { 1, 0 }, { 0, 1 } };
    for (int p = n - 2; p; p >>= 1) {
        if (p & 1)
            matrix_mulipty(2, 2, op_matrix, 2, 2, matrix, op_matrix);
        matrix_mulipty(2, 2, matrix, 2, 2, matrix, matrix);
    }
    matrix_mulipty(2, 2, op_matrix, 2, 1, res_vec, res_vec);
    return res_vec[0][0];
}

// Formula
int climbStairs_MK3(int n)
{
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)(fibn / sqrt5);
}
