#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        if (a == e)
            return c == e && d > min(b, f) && d < max(b, f) ? 2 : 1;
        if (b == f)
            return d == f && c > min(a, e) && c < max(a, e) ? 2 : 1;
        if (abs(c - e) == abs(d - f))
            return abs(a - e) == abs(b - f) && a > min(c, e) && a < max(c, e) && b > min(d, f) && b < max(d, f) ? 2 : 1;
        return 2;
    }
};
