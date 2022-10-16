#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        enum COLOR { WHITE = -1, RED, BLUE };

        vector<int> color_map(n + 1, COLOR::WHITE);
        unordered_map<int, vector<int>> graph;
        for (const vector<int>& dislike : dislikes) {
            graph[dislike[0]].emplace_back(dislike[1]);
            graph[dislike[1]].emplace_back(dislike[0]);
        }

        function<bool(int, int)> dfs = [&](int i, int color) -> bool {
            color_map[i] = color;
            for (const int& neighbour : graph[i]) {
                if (color_map[neighbour] == color)
                    return false;
                if (color_map[neighbour] == COLOR::WHITE && !dfs(neighbour, color ^ 1))
                    return false;
            }
            return true;
        };

        for (int i = 1; i <= n; i++)
            if (color_map[i] == COLOR::WHITE && !dfs(i, COLOR::BLUE))
                return false;
        return true;
    }
};
