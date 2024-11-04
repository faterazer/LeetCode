#include <climits>
#include <functional>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        int n = price.size(), idx = 0;
        for (const vector<int> &offer : special) {
            int cnt = 0, direct_price = 0;
            for (int i = 0; i < n; ++i) {
                cnt += offer[i];
                direct_price += offer[i] * price[i];
            }
            if (cnt > 0 && direct_price > offer[n])
                special[idx++] = offer;
        }
        special.resize(idx);

        map<vector<int>, int> memo;

        function<int(vector<int>&)> dfs = [&](vector<int> &state) -> int {
            if (memo.contains(state))
                return memo[state];
            
            for (int x : state)
                if (x < 0)
                    return INT_MAX / 2;
            
            int min_price = inner_product(state.begin(), state.end(), price.begin(), 0);
            for (const vector<int> &offer : special) {
                for (int i = 0; i < n; ++i)
                    state[i] -= offer[i];

                min_price = min(min_price, offer[n] + dfs(state));

                for (int i = 0; i < n; ++i)
                    state[i] += offer[i];
            }
            memo[state] = min_price;
            return memo[state];
        };

        return dfs(needs);
    }
};
