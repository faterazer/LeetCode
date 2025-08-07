#include <cmath>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n)
    {
        int x = (21 - sqrt(441.0 - 8 * n)) / 2;
        return x % 2;
    }
};
