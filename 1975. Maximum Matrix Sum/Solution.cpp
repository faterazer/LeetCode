#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        long long result = 0;
        int mn = numeric_limits<int>::max(), neg_cnt = 0;
        for (const vector<int>& row : matrix) {
            for (int x : row) {
                result += abs(x);
                neg_cnt += x < 0;
                mn = min(mn, abs(x));
            }
        }
        if (neg_cnt & 1)
            result -= 2 * mn;
        return result;
    }
};
