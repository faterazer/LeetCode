#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
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

        int visited = 0;
        while (!Q.empty()) {
            ++visited;
            int node = Q.front();
            Q.pop();
            for (int neighbour : adjacency_list[node])
                if (--in_degrees[neighbour] == 0)
                    Q.emplace(neighbour);
        }
        return visited == numCourses;
    }
};
