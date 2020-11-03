#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int i = 0, j = A.size() - 1;
        while (i < j && A[i] < A[i + 1])
            i++;
        while (j > i && A[j] < A[j - 1])
            j--;
        return i > 0 && j < A.size() - 1 && i == j;
    }
};
