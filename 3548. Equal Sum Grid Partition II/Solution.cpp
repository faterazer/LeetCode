#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (const vector<int>& row : grid)
            total += reduce(row.begin(), row.end(), 0LL);

        auto check = [&](int M, int N, auto get) -> bool {
            if (M <= 1)
                return false;

            long long top_sum = 0;
            for (int j = 0; j < N; ++j)
                top_sum += get(0, j);
            long long diff = 2 * top_sum - total;
            if (diff == 0 || diff == get(0, 0) || diff == get(0, N - 1))
                return true;

            if (M == 2)
                return false;

            unordered_set<long long> seen;
            seen.insert(0);
            for (int j = 0; j < N; ++j)
                seen.insert(get(0, j));
            for (int i = 1; i < M - 1; ++i) {
                for (int j = 0; j < N; ++j) {
                    int val = get(i, j);
                    top_sum += val;
                    seen.insert(val);
                }

                diff = 2 * top_sum - total;
                if (N == 1) {
                    if (diff == 0 || diff == get(0, 0) || diff == get(i, 0))
                        return true;
                } else {
                    if (seen.contains(diff))
                        return true;
                }
            }
            return false;
        };

        return check(m, n, [&](int r, int c) { return grid[r][c]; }) || check(m, n, [&](int r, int c) { return grid[m - 1 - r][c]; }) || check(n, m, [&](int r, int c) { return grid[c][r]; }) || check(n, m, [&](int r, int c) { return grid[c][n - 1 - r]; });
    }
};
