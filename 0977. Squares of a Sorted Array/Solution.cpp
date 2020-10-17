#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> ret(A.size());
        int l = 0, r = A.size() - 1;
        vector<int>::reverse_iterator it = ret.rbegin();
        while (l <= r) {
            if (abs(A[l]) > abs(A[r]))
                *(it++) = pow(A[l++], 2);
            else
                *(it++) = pow(A[r--], 2);
        }
        return ret;
    }
};
