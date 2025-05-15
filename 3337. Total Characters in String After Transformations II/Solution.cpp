#include <vector>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums)
    {
        vector<vector<int>> M(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int j = 1; j <= nums[i]; ++j)
                M[(i + j) % 26][i] += 1;

        vector<vector<int>> v(26, vector<int>(1, 0));
        for (char c : s)
            ++v[c - 'a'][0];
        while (t) {
            if (t & 1)
                v = matrixMultiply(M, v);
            M = matrixMultiply(M, M);
            t >>= 1;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            ans = (ans + v[i][0]) % P;
        return ans;
    }

private:
    vector<vector<int>> matrixMultiply(const vector<vector<int>>& left, const vector<vector<int>>& right)
    {
        int m = left.size(), n = right[0].size(), t = right.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < t; k++)
                    ans[i][j] = (ans[i][j] + 1LL * left[i][k] * right[k][j] % P) % P;
        return ans;
    }

    static constexpr int P = 1e9 + 7;
};
