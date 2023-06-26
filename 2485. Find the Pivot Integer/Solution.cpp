#include <cmath>
using namespace std;

class Solution {
public:
    int pivotInteger(int n)
    {
        int x2 = (n * n + n) / 2;
        int x = sqrt(x2);
        return x * x == x2 ? x : -1;
    }
};
