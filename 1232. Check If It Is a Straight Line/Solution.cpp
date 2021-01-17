#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int A = coordinates[1][1] - coordinates[0][1],B = coordinates[1][0] - coordinates[0][0];
        for (size_t i = 2; i < coordinates.size(); i++)
            if ((coordinates[i][1] - coordinates[0][1]) * B != (coordinates[i][0] - coordinates[0][0]) * A)
                return false;
        return true;
    }
};
