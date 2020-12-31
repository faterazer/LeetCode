#include <vector>
using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        bool increasing = true, decreasing = true;
        for (size_t i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1])
                decreasing = false;
            else if (A[i] < A[i - 1])
                increasing = false;
        }
        return increasing || decreasing;
    }
};
