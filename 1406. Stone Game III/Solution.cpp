#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        vector<int> f(stoneValue.size() + 3, 0);
        int suf_sum = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            suf_sum += stoneValue[i];
            f[i] = suf_sum - min(f[i + 1], min(f[i + 2], f[i + 3]));
        }
        if (2 * f[0] > suf_sum)
            return "Alice";
        else if (2 * f[0] < suf_sum)
            return "Bob";
        else
            return "Tie";
    }
};
