#include <vector>
using namespace std;

class Solution
{
public:
    // 低 8 位存原始数据，中 8 位存平均值
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int m = M.size(), n = M[0].size();
        vector<pair<int, int>> dirs = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = M[i][j], count = 1;
                for (const pair<int, int> &d : dirs) {
                    int nx = i + d.first;
                    int ny = j + d.second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    sum += (M[nx][ny] & 0xFF);
                    count += 1;
                }
                M[i][j] |= (sum / count) << 8;
            }
        }

        for (vector<int> &row : M)
            for (int &e : row)
                e >>= 8;
        return M;
    }
};
