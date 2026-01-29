#include <array>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        constexpr int INF = numeric_limits<int>::max() / 2;
        array<array<int, 26>, 26> dist;
        for (array<int, 26>& row : dist)
            row.fill(INF);
        for (int i = 0; i < 26; ++i)
            dist[i][i] = 0;
        for (auto [xc, yc, c] : ranges::views::zip(original, changed, cost)) {
            int x = xc - 'a', y = yc - 'a';
            dist[x][y] = min(dist[x][y], c);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF)
                    continue;
                for (int j = 0; j < 26; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        long long result = 0;
        for (auto [sc, tc] : ranges::views::zip(source, target)) {
            int d = dist[sc - 'a'][tc - 'a'];
            if (d == INF)
                return -1;
            result += d;
        }
        return result;
    }
};
