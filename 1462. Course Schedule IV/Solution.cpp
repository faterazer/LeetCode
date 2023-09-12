#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degrees(numCourses, 0);
        vector<vector<int>> dep_matrix(numCourses, vector<int>(numCourses, 0));

        for (const vector<int>& p : prerequisites) {
            graph[p[0]].emplace_back(p[1]);
            ++in_degrees[p[1]];
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
            if (in_degrees[i] == 0)
                Q.emplace(i);

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            for (int neighbour : graph[node]) {
                dep_matrix[node][neighbour] = 1;
                for (int i = 0; i < numCourses; i++)
                    dep_matrix[i][neighbour] |= dep_matrix[i][node];
                if (--in_degrees[neighbour] == 0)
                    Q.emplace(neighbour);
            }
        }

        vector<bool> res;
        for (const vector<int>& q : queries)
            res.emplace_back(dep_matrix[q[0]][q[1]]);
        return res;
    }
};
