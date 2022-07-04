#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size(), inc = 1, dec = 0, pre = 1, res = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                inc = pre;
                res += pre;
            } else if (ratings[i] < ratings[i - 1]) {
                ++dec;
                if (dec == inc) {
                    ++dec;
                }
                res += dec;
                pre = 1;
            }
        }
        return res;
    }
};
