#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0, d = 0;
        for (const char& c : instructions) {
            if (c == 'L')
                d = (d + 3) % 4;
            else if (c == 'R')
                d = (d + 1) % 4;
            else {
                x += directions[d][0];
                y += directions[d][1];
            }
        }
        return (x == 0 && y == 0) || d > 0;
    }

private:
    vector<vector<int>> directions { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
};
