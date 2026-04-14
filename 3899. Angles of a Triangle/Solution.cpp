#include <algorithm>
#include <cmath>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides)
    {
        ranges::sort(sides);
        int a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c)
            return {};
        const double rad = 180 / acos(-1);
        double A = acos(1.0 * (b * b + c * c - a * a) / (b * c * 2)) * rad;
        double B = acos(1.0 * (a * a + c * c - b * b) / (a * c * 2)) * rad;
        return {A, B, 180 - A - B};
    }
};
