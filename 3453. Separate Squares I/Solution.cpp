#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares)
    {
        long long total_area = 0;
        map<int, long long> diff;
        for (const vector<int>& square : squares) {
            int y = square[1], side = square[2];
            total_area += 1LL * side * side;
            diff[y] += side;
            diff[y + side] -= side;
        }

        long long area = 0, sum_side = 0;
        for (auto it = diff.begin(); it != diff.end();) {
            auto [y, side] = *it;
            int next_y = (++it)->first;
            sum_side += side;
            area += 1LL * sum_side * (next_y - y);
            if (area * 2 >= total_area)
                return next_y - (area * 2 - total_area) / (2.0 * sum_side);
        }
        return -1.0;
    }
};
