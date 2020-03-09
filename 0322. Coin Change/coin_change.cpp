#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange_MK1(vector<int> &coins, int amount);
    int coinChange_MK2(vector<int> &coins, int amount);
private:
    void helper(vector<int> &coins, int amount, int start, int cur, int &res);
};

int Solution::coinChange_MK1(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < amount + 1; i++) {
        for (const int &coin : coins) {
            if (i - coin < 0)
                continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int Solution::coinChange_MK2(vector<int> &coins, int amount)
{
    int res = amount + 1;
    sort(coins.begin(), coins.end());
    helper(coins, amount, coins.size() - 1, 0, res);
    return res == amount + 1 ? -1 : res;
}

void Solution::helper(vector<int> &coins, int amount, int start, int cur, int &res)
{
    if (start < 0)
        return;
    if (amount % coins[start] == 0) {
        res = min(res, cur + amount / coins[start]);
        return;
    }
    for (int i = amount / coins[start]; i >= 0; i--) {
        if (cur + i >= res - 1)
            break;
        helper(coins, amount - i * coins[start], start - 1, cur + i, res);
    }
}
