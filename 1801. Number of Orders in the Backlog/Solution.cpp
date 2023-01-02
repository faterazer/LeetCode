#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders)
    {
        for (const vector<int>& order : orders) {
            if (order[2] == 0)
                buy(make_pair(order[0], order[1]));
            else
                sell(make_pair(order[0], order[1]));
        }

        constexpr int P = 1e9 + 7;
        int res = 0;
        while (!buy_orders.empty()) {
            res = (res + buy_orders.top().second) % P;
            buy_orders.pop();
        }
        while (!sell_orders.empty()) {
            res = (res + sell_orders.top().second) % P;
            sell_orders.pop();
        }
        return res;
    }

    void buy(pair<int, int>&& o)
    {
        while (!sell_orders.empty() && sell_orders.top().first <= o.first) {
            pair<int, int> p = sell_orders.top();
            sell_orders.pop();
            if (p.second <= o.second)
                o.second -= p.second;
            else {
                p.second -= o.second;
                o.second = 0;
                sell_orders.emplace(p);
                break;
            }
        }
        if (o.second)
            buy_orders.emplace(o);
    }

    void sell(pair<int, int>&& o)
    {
        while (!buy_orders.empty() && buy_orders.top().first >= o.first) {
            pair<int, int> p = buy_orders.top();
            buy_orders.pop();
            if (p.second <= o.second)
                o.second -= p.second;
            else {
                p.second -= o.second;
                o.second = 0;
                buy_orders.emplace(p);
                break;
            }
        }
        if (o.second)
            sell_orders.emplace(o);
    }

private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell_orders;
    priority_queue<pair<int, int>> buy_orders;
};
