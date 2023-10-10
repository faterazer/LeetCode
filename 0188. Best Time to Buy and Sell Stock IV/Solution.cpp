#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int f[k + 1][2];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= k; i++)
            f[i][0] = INT_MIN;
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                f[i][0] = max(f[i][0], f[i - 1][1] - price);
                f[i][1] = max(f[i][1], f[i][0] + price);
            }
        }
        return f[k][1];
    }
};
