#include <vector>
using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts)
    {
        int pre = -1, res = 0, n = forts.size();
        for (int i = 0; i < n; i++) {
            if (forts[i] != 0) {
                if (pre > -1 && forts[i] != forts[pre])
                    res = max(res, i - pre - 1);
                pre = i;
            }
        }
        return res;
    }
};
