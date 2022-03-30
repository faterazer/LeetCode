#include <functional>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {
        set<int> available;
        for (int i = 0; i < k; ++i)
            available.emplace(i);
        vector<int> servers_counter(k, 0);
        int requestsSize = arrival.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        for (int i = 0; i < requestsSize; ++i) {
            int arrival_time = arrival[i], time_needed = load[i];
            while (!busy.empty() && busy.top().first <= arrival_time) {
                available.emplace(busy.top().second);
                busy.pop();
            }
            if (available.empty())
                continue;
            auto server = available.lower_bound(i % k);
            if (server == available.end())
                server = available.begin();
            busy.emplace(arrival_time + time_needed, *server);
            servers_counter[*server] += 1;
            available.erase(server);
        }
        int max_val = *max_element(servers_counter.begin(), servers_counter.end());
        vector<int> res;
        for (int i = 0; i < k; ++i)
            if (servers_counter[i] == max_val)
                res.emplace_back(i);
        return res;
    }
};
