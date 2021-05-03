#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int res = 0;
        for (const vector<int> &account : accounts)
            res = max(res, accumulate(account.begin(), account.end(), 0));
        return res;
    }
};
