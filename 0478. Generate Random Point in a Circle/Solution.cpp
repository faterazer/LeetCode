#include <cmath>
#include <random>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(double _radius, double _x_center, double _y_center)
        : radius(_radius)
        , x_center(_x_center)
        , y_center(_y_center)
        , dis(0, 1.0)
    {
    }

    vector<double> randPoint()
    {
        double r = sqrt(dis(engine)), theta = dis(engine) * _2PI;
        return { x_center + r * cos(theta) * radius, y_center + r * sin(theta) * radius };
    }

private:
    double radius, x_center, y_center;
    default_random_engine engine;
    uniform_real_distribution<double> dis;
    constexpr static double _2PI = 3.1415926 * 2;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
