#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int m = strs.size(), n = strs[0].size(), result = 0;
        vector<int> prev_sorted(m, 0);
        for (int j = 0; j < n; ++j) {
            bool del = false;
            for (int i = 1; i < m; ++i) {
                if (!prev_sorted[i] && strs[i - 1][j] > strs[i][j]) {
                    ++result;
                    del = true;
                    break;
                }
            }

            if (!del) {
                for (int i = 1; i < m; ++i)
                    prev_sorted[i] = prev_sorted[i] || (strs[i - 1][j] < strs[i][j]);
            }
        }
        return result;
    }
};
