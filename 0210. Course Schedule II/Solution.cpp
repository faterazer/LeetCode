#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adjacency_list(numCourses);
        vector<int> in_degrees(numCourses, 0);
        for (const vector<int>& info : prerequisites) {
            adjacency_list[info[1]].emplace_back(info[0]);
            in_degrees[info[0]]++;
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
            if (!in_degrees[i])
                Q.emplace(i);

        vector<int> res;
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            res.emplace_back(node);
            for (int neighbour : adjacency_list[node])
                if (--in_degrees[neighbour] == 0)
                    Q.emplace(neighbour);
        }
        return static_cast<int>(res.size()) == numCourses ? res : vector<int>();
    }
};
