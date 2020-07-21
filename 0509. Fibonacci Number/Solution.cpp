#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    // Binets Method
    int fib_MK1(int N)
    {
        if (N == 0 || N == 1)
            return N;
        N--;
        vector<vector<int>> A = {{1, 1}, {1, 0}};
        vector<vector<int>> ans = {{1, 0}, {0, 1}};
        while (N) {
            if (N % 2)
                ans = matrixMultiply(ans, A);
            A = matrixMultiply(A, A);
            N /= 2;
        }
        return ans[0][0];
    }

    // Fibonacci formula
    int fib_MK2(int N)
    {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, N) - pow((1 - sqrt5) / 2, N);
        return fibn / sqrt5;
    }
private:
    vector<vector<int>> matrixMultiply(const vector<vector<int>> &left, const vector<vector<int>> &right)
    {
        int m = left.size(), n = right[0].size(), t = right.size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < t; k++)
                    ret[i][j] += left[i][k] * right[k][j];
        return ret;
    }
};
