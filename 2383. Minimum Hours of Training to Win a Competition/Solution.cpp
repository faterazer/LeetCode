#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int res = max(accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy, 0);
        for (const int& exp : experience) {
            if (exp >= initialExperience) {
                res += exp + 1 - initialExperience;
                initialExperience = exp + 1;
            }
            initialExperience += exp;
        }

        return res;
    }
};
