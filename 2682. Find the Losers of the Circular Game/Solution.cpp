#include <vector>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> visited(n, 0);
        for (int i = 0, d = k; !visited[i]; d += k) {
            visited[i] = 1;
            i = (i + d) % n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                res.emplace_back(i);
        return res;
    }
};
