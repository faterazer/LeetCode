#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix)
    {
        vector<int> result;
        result.reserve(matrix.size());
        for (const vector<int>& row : matrix)
            result.push_back(reduce(row.cbegin(), row.cend(), 0));
        return result;
    }
};
