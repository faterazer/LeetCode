#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double res = 0.0;
        for (size_t i = 0; i < points.size() - 2; i++)
            for (size_t j = i + 1; j < points.size() - 1; j++)
                for (size_t k = j + 1; k < points.size(); k++)
                    res = max(res, area(points[i], points[j], points[k]));
        return res;
    }

private:
    double area(const vector<int> &a, const vector<int> &b, const vector<int> &c)
    {
        return 0.5 * abs((a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0]));
    }
};
