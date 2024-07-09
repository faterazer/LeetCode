#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        int cur_time = 0;
        double res = 0.0;
        for (const vector<int>& c : customers) {
            cur_time = max(cur_time, c[0]) + c[1];
            res += cur_time - c[0];
        }
        return res / customers.size();
    }
};
