#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));
        vector<vector<long long>> g(n + 1, vector<long long>(m + 1));
        for (int K = 1; K <= k; ++K) {
            fill(g[K - 1].begin() + K, g[K - 1].end() - (k - K), numeric_limits<long long>::min());
            for (int i = K; i <= n - (k - K); ++i) {
                g[i][K - 1] = numeric_limits<long long>::min();
                for (int j = K; j <= m - (k - K); ++j)
                    g[i][j] = max(max(g[i - 1][j], g[i][j - 1]), f[i - 1][j - 1] + 1LL * nums1[i - 1] * nums2[j - 1]);
            }
            swap(f, g);
        }
        return f[n][m];
    }
};
