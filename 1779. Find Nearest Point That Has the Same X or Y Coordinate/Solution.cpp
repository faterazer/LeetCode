#include <vector>
using namespace std;

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int res = -1, dist = INT_MAX;
        for (size_t i = 0; i < points.size(); i++) {
            int xx = points[i][0], yy = points[i][1];
            if (xx == x || yy == y) {
                int tmp_dist = abs(xx - x) + abs(yy - y);
                if (tmp_dist < dist) {
                    dist = tmp_dist;
                    res = i;
                }
            }
        }
        return res;
    }
};
