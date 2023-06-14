#include <vector>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int sum = 0, last_idx = -1, res = 0;
        for (int idx : flips) {
            last_idx = max(last_idx, idx);
            if (++sum == last_idx)
                res++;
        }
        return res;
    }
};
