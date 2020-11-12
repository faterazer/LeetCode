#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        for (size_t i = 0, j = 1; i < A.size(); i += 2) {
            if (A[i] & 1) {
                while (A[j] & 1)
                    j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};
