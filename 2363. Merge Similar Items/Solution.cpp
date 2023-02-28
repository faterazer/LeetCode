#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2)
    {
        map<int, int> dict;
        for (const vector<int> &v : items1)
            dict[v[0]] += v[1];
        for (const vector<int> &v : items2)
            dict[v[0]] += v[1];
        vector<vector<int>> res;
        for (const auto &[k , v] : dict)
            res.push_back({k, v});
        return res;
    }
};
