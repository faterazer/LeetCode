#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        int bg = rounds[0], ed = rounds.back();
        vector<int> res;
        if (bg <= ed) {
            for (int i = bg; i <= ed; i++)
                res.emplace_back(i);
        } else {
            for (int i = 1; i <= ed; i++)
                res.emplace_back(i);
            for (int i = bg; i <= n; i++)
                res.emplace_back(i);
        }
        return res;
    }
};
