#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points);
};

int Solution::numberOfBoomerangs(vector<vector<int>> &points)
{
    int ret = 0;
    for (size_t i = 0; i < points.size(); i++) {
        unordered_map<int, int> map;
        for (size_t j = 0; j < points.size(); j++) {
            if (i == j)
                continue;
            int dist = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
            ret += (map[dist]++) * 2;
        }
    }
    return ret;
}
