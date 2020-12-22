#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int idx = 1;    // index of dirs, represents current direction.
        set<vector<int>> obs(obstacles.begin(), obstacles.end());
        int res = 0;
        vector<int> coord{0, 0};
        for (const int &command : commands) {
            if (command == -1)
                idx = (idx + 1) % dirs.size();
            else if (command == -2)
                idx = (idx - 1) % dirs.size();
            else {
                for (int i = 0; i < command; i++) {
                    coord[0] += dirs[idx][0];
                    coord[1] += dirs[idx][1];
                    if (obs.count(coord)) {
                        coord[0] -= dirs[idx][0];
                        coord[1] -= dirs[idx][1]; 
                        break;
                    }
                }
                res = max(res, coord[0] * coord[0] + coord[1] * coord[1]);
            }
        }
        return res;
    }
};
