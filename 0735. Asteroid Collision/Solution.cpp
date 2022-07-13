#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> stk, res;
        for (const int& asteroid : asteroids) {
            if (asteroid > 0) {
                stk.emplace_back(asteroid);
                continue;
            }
            while (!stk.empty() && stk.back() + asteroid < 0)
                stk.pop_back();
            if (stk.empty())
                res.emplace_back(asteroid);
            else if (stk.back() + asteroid == 0)
                stk.pop_back();
        }
        res.insert(res.end(), stk.begin(), stk.end());
        return res;
    }
};
