#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> row(query_row + 1);
        row[0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = i; j >= 0; --j) {
                double excess = max(0.0, row[j] - 1.0);
                if (excess > 0) {
                    row[j + 1] += excess / 2;
                    row[j] = excess / 2;
                } else
                    row[j] = 0;
            }
        }
        return min(1.0, row[query_glass]);
    }
};
