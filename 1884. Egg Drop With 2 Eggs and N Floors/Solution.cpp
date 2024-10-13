#include <cmath>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n)
    {
        return ceil(sqrt(8 * n + 1)) / 2;
    }
};
