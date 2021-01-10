#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        int res = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A[j][i] < A[j - 1][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
