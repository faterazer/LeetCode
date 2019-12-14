#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows);
};

vector<vector<int>> Solution::generate(int numRows)
{
    vector<vector<int>> ret;
    if (!numRows)
        return ret;
    ret.emplace_back(vector<int>(1, 1));
    for (int i = 1; i < numRows; i++) {
        vector<int> row(1, 1);
        vector<int> &last_row = ret[i-1];
        for (size_t j = 1; j < last_row.size(); j++)
            row.emplace_back(last_row[j] + last_row[j-1]);
        row.emplace_back(1);
        ret.emplace_back(row);
    }
    return ret;
}
