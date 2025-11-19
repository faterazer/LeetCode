#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findFinalValue_MK1(vector<int>& nums, int original)
    {
        unordered_set<int> ust;
        for (int x : nums) {
            int k = x / original;
            if (x % original == 0 && (k & (k - 1)) == 0)
                ust.emplace(x);
        }

        while (ust.contains(original))
            original *= 2;
        return original;
    }

    int findFinalValue_MK2(vector<int>& nums, int original)
    {
        unsigned mask = 0;
        for (int x : nums) {
            int k = x / original;
            if (x % original == 0 && (k & (k - 1)) == 0)
                mask |= k;
        }

        mask = ~mask;
        return original * (mask & -mask);
    }
};
