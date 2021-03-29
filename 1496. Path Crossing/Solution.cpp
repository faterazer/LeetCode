#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        auto pairHash = [](const pair<int, int> &p) {
            return p.first * 100000 + p.second;
        };
        unordered_set<pair<int, int>, decltype(pairHash)> visited(0, pairHash);
        int x = 0, y = 0;
        visited.emplace(x, y);
        for (const char &d : path) {
            if (d == 'N')
                y++;
            else if (d == 'S')
                y--;
            else if (d == 'E')
                x++;
            else
                x--;
            if (visited.count({x, y}))
                return true;
            visited.emplace(x, y);
        }
        return false;
    }
};
