#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0, total = 0;
        for (auto it = satisfaction.rbegin(); it != satisfaction.rend() && *it > -total; it++) {
            total += *it;
            res += total;
        }
        return res;
    }
};
