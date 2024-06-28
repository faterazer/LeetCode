#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<long long> degrees(n, 0);
        for (const vector<int>& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        ranges::sort(degrees);
        long long res = 0;
        for (int i = 0; i < n; i++)
            res += (i + 1) * degrees[i];
        return res;
    }
};
