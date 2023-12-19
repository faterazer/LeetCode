#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int l = 0, r = mat.size() - 2;
        while (l <= r) {
            int i = l + ((r - l) >> 1);
            int j = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
            if (mat[i][j] < mat[i + 1][j])
                l = i + 1;
            else
                r = i - 1;
        }
        return { l, static_cast<int>(max_element(mat[l].begin(), mat[l].end()) - mat[l].begin()) };
    }
};
