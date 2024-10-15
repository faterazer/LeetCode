#include <cmath>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue)
    {
        auto F = [](int x, int y) -> int {
            int odd = sqrt(x);
            int even = (sqrt(1 + 4 * y) - 1) / 2;
            return odd > even ? 2 * even + 1 : 2 * odd;
        };
        return fmax(F(red, blue), F(blue, red));
    }
};
