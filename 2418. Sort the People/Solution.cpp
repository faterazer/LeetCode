#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int& i, const int& j) {
            return heights[i] > heights[j];
        });
        vector<string> res;
        for (const int i : idxs)
            res.emplace_back(names[i]);
        return res;
    }
};
