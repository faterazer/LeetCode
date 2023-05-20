#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX = 8;
int comb[MAX][MAX];

int init = []() {
    for (int i = 0; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
    return 0;
}();

class Solution {
public:
    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> cnt;
        for (char c : tiles)
            cnt[c]++;
        vector<int> f(tiles.size() + 1, 0);
        f[0] = 1;
        int n = 0;
        for (const auto& [_, c] : cnt) {
            n += c;
            for (int i = n; i; i--)
                for (int j = 1; j <= i && j <= c; j++)
                    f[i] += f[i - j] * comb[i][j];
        }
        return accumulate(f.begin() + 1, f.end(), 0);
    }
};
