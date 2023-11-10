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
            int need = (success - 1) / spell;
            int idx = upper_bound(potions.begin(), potions.end(), need) - potions.begin();
            res.emplace_back(potions.size() - idx);
        }
        return res;
    }
};
