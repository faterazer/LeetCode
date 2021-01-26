#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int res = 0;
        unordered_map<int, int> umap;
        for (const vector<int> &p : dominoes)
            res += umap[min(p[0], p[1]) * 10 + max(p[0], p[1])]++;
        return res;
    }
};
