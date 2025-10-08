#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int spell : spells) {
            long long need = (success - 1) / spell;
            res.emplace_back(potions.end() - upper_bound(potions.begin(), potions.end(), need));
        }
        return res;
    }
};
