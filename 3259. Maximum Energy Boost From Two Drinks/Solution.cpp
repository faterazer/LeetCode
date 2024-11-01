#include <vector>
using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
    {
        int n = energyDrinkA.size();
        long long a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            long long na = max(a + energyDrinkA[i], b);
            long long nb = max(a, energyDrinkB[i] + b);
            a = na;
            b = nb;
        }
        return max(a, b);
    }
};
