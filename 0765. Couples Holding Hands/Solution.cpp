#include <vector>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row)
    {
        vector<int> pos(row.size());
        for (size_t i = 0; i < row.size(); ++i)
            pos[row[i]] = i;

        int res = 0;
        for (size_t i = 0; i < row.size() - 1; i += 2) {
            int partner = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
            for (int j = i + 1; row[j] != partner;) {
                int partner2 = (row[j] & 1) ? row[j] - 1 : row[j] + 1;
                int pos2 = (pos[partner2] & 1) ? pos[partner2] - 1 : pos[partner2] + 1;
                swap(pos[row[j]], pos[partner2]);
                swap(row[j], row[pos2]);
                ++res;
            }
        }
        return res;
    }
};
