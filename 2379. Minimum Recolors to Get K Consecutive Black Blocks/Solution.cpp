#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int cnt_W = 0, i = 0, n = blocks.size();
        for (; i < k; i++)
            cnt_W += blocks[i] == 'W';

        int res = cnt_W;
        for (; i < n; i++) {
            cnt_W -= blocks[i - k] == 'W';
            cnt_W += blocks[i] == 'W';
            res = min(res, cnt_W);
        }
        return res;
    }
};
