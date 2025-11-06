#include <algorithm>
#include <functional>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度：O(clogc + n + qlogc) 或者 O(c + n + qlogc)，取决于实现，其中 n 是 connections 的长度，q 是 queries 的长度。
    // 空间复杂度：O(c+n)。
    vector<int> processQueries_MK1(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        vector<vector<int>> grid(c + 1);
        for (const vector<int>& conn : connections) {
            grid[conn[0]].push_back(conn[1]);
            grid[conn[1]].push_back(conn[0]);
        }

        vector<int> node2heap(c + 1, -1);
        vector<priority_queue<int, vector<int>, greater<>>> heaps;
        priority_queue<int, vector<int>, greater<>> temp_pq;

        function<void(int)> dfs = [&](int x) -> void {
            node2heap[x] = heaps.size();
            temp_pq.emplace(x);
            for (int y : grid[x])
                if (node2heap[y] == -1)
                    dfs(y);
        };

        for (int i = 1; i <= c; ++i) {
            if (node2heap[i] == -1) {
                dfs(i);
                heaps.emplace_back(std::move(temp_pq));
            }
        }

        vector<int> ans;
        vector<int8_t> online(c + 1, 1);
        for (const vector<int>& query : queries) {
            int type = query[0], node = query[1];
            if (type == 2)
                online[node] = 0;
            else if (online[node])
                ans.emplace_back(node);
            else {
                auto& heap = heaps[node2heap[node]];
                while (!heap.empty() && !online[heap.top()])
                    heap.pop();
                ans.emplace_back(heap.empty() ? -1 : heap.top());
            }
        }
        return ans;
    }

    // 时间复杂度：O(c+n+q)，其中 n 是 connections 的长度，q 是 queries 的长度。
    // 空间复杂度：O(c+n)。
    vector<int> processQueries_MK2(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        vector<vector<int>> grid(c + 1);
        for (const vector<int>& conn : connections) {
            grid[conn[0]].push_back(conn[1]);
            grid[conn[1]].push_back(conn[0]);
        }

        vector<int> node2component(c + 1, -1);
        int component_cnt = 0;

        function<void(int)> dfs = [&](int x) -> void {
            node2component[x] = component_cnt;
            for (int y : grid[x])
                if (node2component[y] == -1)
                    dfs(y);
        };

        for (int i = 1; i <= c; ++i) {
            if (node2component[i] == -1) {
                dfs(i);
                ++component_cnt;
            }
        }

        vector<int> offline_time(c + 1, INT_MAX);
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0], node = queries[i][1];
            if (type == 2)
                offline_time[node] = i;
        }

        vector<int> mn(component_cnt, INT_MAX);
        for (int i = 1; i <= c; ++i) {
            int component = node2component[i];
            if (offline_time[i] == INT_MAX)
                mn[component] = min(mn[component], i);
        }

        vector<int> ans;
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0], node = queries[i][1];
            int component = node2component[node];
            if (type == 2) {
                if (offline_time[node] == i)
                    mn[component] = min(mn[component], node);
            } else if (i < offline_time[node])
                ans.emplace_back(node);
            else if (mn[component] != INT_MAX)
                ans.emplace_back(mn[component]);
            else
                ans.emplace_back(-1);
        }
        ranges::reverse(ans);
        return ans;
    }
};
