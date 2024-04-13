#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        vector<int> degree(n, 0);
        for (const vector<int>& edge : edges)
            ++degree[edge[1]];

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                if (res != -1)
                    return -1;
                res = i;
            }
        }
        return res;
    }
};
