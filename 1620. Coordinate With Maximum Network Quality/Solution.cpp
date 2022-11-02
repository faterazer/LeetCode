#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius)
    {
        int x_min = 0, x_max = 0, y_min = 0, y_max = 0;
        for (const vector<int>& tower : towers) {
            x_min = min(x_min, tower[0]);
            x_max = max(x_max, tower[0]);
            y_min = min(y_min, tower[1]);
            y_max = max(y_max, tower[1]);
        }

        vector<int> res(2);
        int max_quality = 0;
        for (int x = x_min; x <= x_max; x++) {
            for (int y = y_min; y <= y_max; y++) {
                int quality = 0;
                for (const vector<int>& tower : towers) {
                    int d2 = (x - tower[0]) * (x - tower[0]) + (y - tower[1]) * (y - tower[1]);
                    if (d2 > radius * radius)
                        continue;
                    quality += floor(static_cast<double>(tower[2]) / (1.0 + sqrt(d2)));
                }
                if (quality > max_quality) {
                    max_quality = quality;
                    res[0] = x;
                    res[1] = y;
                }
            }
        }
        return res;
    }
};
