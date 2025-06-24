#include <vector>
using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (const vector<int>& d : dig)
            grid[d[0]][d[1]] = 1;

        int ans = 0;
        for (const vector<int>& a : artifacts) {
            bool can_extract = true;
            for (int i = a[0]; i <= a[2]; ++i) {
                for (int j = a[1]; j <= a[3]; ++j) {
                    if (grid[i][j] == 0) {
                        can_extract = false;
                        break;
                    }
                }
                if (!can_extract)
                    break;
            }
            ans += can_extract;
        }
        return ans;
    }
};
