#include <algorithm>
using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        return (mainTank + min((mainTank - 1) / 4, additionalTank)) * 10;
    }
};
