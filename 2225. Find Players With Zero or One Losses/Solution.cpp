#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, int> degrees;
        for (const vector<int> &m : matches) {
            if (!degrees.contains(m[0]))
                degrees[m[0]] = 0;
            degrees[m[1]]++;
        }
        vector<vector<int>> res(2);
        for (const auto& [k, v] : degrees) {
            if (v == 0)
                res[0].emplace_back(k);
            else if (v == 1)
                res[1].emplace_back(k);
        }
        return res;
    }
};
