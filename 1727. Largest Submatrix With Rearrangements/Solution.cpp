#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {
        int n = matrix[0].size(), result = 0;
        vector<int> heights(n);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        vector<int> non_zeros(n);

        for (const vector<int>& row : matrix) {
            int p = 0, q = 0;
            for (int j : ids) {
                if (row[j] == 0) {
                    heights[j] = 0;
                    ids[p++] = j;
                } else {
                    ++heights[j];
                    non_zeros[q++] = j;
                }
            }

            for (int i = p; i < n; ++i) {
                ids[i] = non_zeros[i - p];
                result = max(result, heights[ids[i]] * (n - i));
            }
        }
        return result;
    }
};
