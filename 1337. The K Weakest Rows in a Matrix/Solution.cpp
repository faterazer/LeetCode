#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> buff;
        for (size_t i = 0; i < mat.size(); i++)
            buff.emplace_back(mat[i].rend() - upper_bound(mat[i].rbegin(), mat[i].rend(), 0), i);
        sort(buff.begin(), buff.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.emplace_back(buff[i].second);
        return res;
    }
};
