#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> groups;
        for (size_t i = 0; i < groupSizes.size(); ++i) {
            groups[groupSizes[i]].emplace_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back({});
                swap(res.back(), groups[groupSizes[i]]);
            }
        }
        return res;
    }
};
