#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int ans = 0, min_s = 0, s = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            s += gas[i] - cost[i];
            if (s < min_s) {
                min_s = s;
                ans = i + 1;
            }
        }
        return s < 0 ? -1 : ans;
    }
};
