#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int n = strs.size(), m = strs[0].size(), result = 0;
        vector<int> ambiguous_rows(n - 1);
        ranges::iota(ambiguous_rows, 0);

        for (int j = 0; j < m; ++j) {
            bool must_delete = false;
            for (int i : ambiguous_rows) {
                if (strs[i][j] > strs[i + 1][j]) {
                    must_delete = true;
                    ++result;
                    break;
                }
            }

            if (!must_delete) {
                int size = 0;
                for (int i : ambiguous_rows)
                    if (strs[i][j] == strs[i + 1][j])
                        ambiguous_rows[size++] = i;
                ambiguous_rows.resize(size);
            }
            if (ambiguous_rows.empty())
                break;
        }
        return result;
    }
};
