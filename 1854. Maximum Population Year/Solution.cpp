#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        unordered_map<int, int> growth_rate;
        int beg = INT_MAX, end = INT_MIN, mx = 0, tmp = 0, res = beg;
        for (const vector<int> &log : logs) {
            growth_rate[log[0]]++;
            growth_rate[log[1]]--;
            beg = min(beg, log[0]);
            end = max(end, log[0]);
        }
        for (int i = beg; i <= end; i++) {
            if (growth_rate.count(i)) {
                tmp += growth_rate[i];
                if (tmp > mx) {
                    mx = tmp;
                    res = i;
                }
            }
        }
        return res;
    }
};
