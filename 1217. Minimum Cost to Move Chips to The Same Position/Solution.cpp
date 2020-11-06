#include <vector>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;
        for (const int &p : position) {
            if (p % 2 == 0)
                even++;
            else
                odd++;
        }
        return min(even, odd);
    }
};
