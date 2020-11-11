#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (vector<int> &row : A) {
            reverse(row.begin(), row.end());
            for (int &e : row)
                e ^= 1;
        }
        return A;
    }
};
