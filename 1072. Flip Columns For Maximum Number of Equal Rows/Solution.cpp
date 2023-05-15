#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int n = matrix[0].size(), res = 0;
        unordered_map<string, int> cnt;
        for (const vector<int>& row : matrix) {
            string s(n, 0);
            for (int j = 0; j < n; j++)
                s[j] = row[j] ^ row[0];
            res = max(res, ++cnt[s]);
        }
        return res;
    }
};
