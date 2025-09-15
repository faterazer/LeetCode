#include <vector>
using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight)
    {
        int ans = 0;
        for (size_t i = 1; i < weight.size(); ++i) {
            if (weight[i] < weight[i - 1]) {
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};
