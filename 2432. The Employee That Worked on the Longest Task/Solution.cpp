#include <vector>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs)
    {
        int max_val = -1, res = n, last_t = 0;
        for (const vector<int>& log : logs) {
            if ((log[1] - last_t) > max_val) {
                max_val = log[1] - last_t;
                res = log[0];
            } else if ((log[1] - last_t) == max_val && log[0] < res)
                res = log[0];
            last_t = log[1];
        }
        return res;
    }
};
