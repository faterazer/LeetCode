#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> stop2buses;
        for (size_t i = 0; i < routes.size(); ++i)
            for (int x : routes[i])
                stop2buses[x].emplace_back(i);
        if (!stop2buses.contains(source) || !stop2buses.contains(target))
            return -1;

        queue<int> Q;
        Q.emplace(source);
        unordered_set<int> visited;
        visited.emplace(source);
        int cnt = 0;
        while (!Q.empty()) {
            ++cnt;
            int qsize = Q.size();
            while (qsize--) {
                int x = Q.front();
                Q.pop();

                for (int i : stop2buses[x]) {
                    for (int y : routes[i]) {
                        if (visited.contains(y))
                            continue;
                        if (y == target)
                            return cnt;
                        Q.emplace(y);
                        visited.emplace(y);
                    }
                    routes[i].clear();
                }
            }
        }
        return -1;
    }
};
