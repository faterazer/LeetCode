#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int ans = triangle[0][0];
        for (size_t i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            ans = triangle[i][0];
            for (size_t j = 1; j < triangle[i].size() - 1; ++j) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                ans = min(ans, triangle[i][j]);
            }
            triangle[i].back() += triangle[i - 1].back();
            ans = min(ans, triangle[i].back());
        }
        return ans;
    }
};
