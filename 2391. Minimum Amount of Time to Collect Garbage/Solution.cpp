#include <functional>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        unordered_set<char> seen;
        int res = garbage[0].size();
        for (int i = garbage.size() - 1; i; i--) {
            seen.insert(garbage[i].begin(), garbage[i].end());
            res += travel[i - 1] * seen.size() + garbage[i].size();
        }
        return res;
    }
};
