#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        int n = questions.size();
        vector<long long> f(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int j = min(i + questions[i][1] + 1, n);
            f[i] = max(f[i + 1], questions[i][0] + f[j]);
        }
        return f[0];
    }
};
