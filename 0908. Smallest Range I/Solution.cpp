#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int smallest = A[0], biggest = A[0];
        for (size_t i = 1; i < A.size(); i++) {
            smallest = min(smallest, A[i]);
            biggest = max(biggest, A[i]);
        }
        return max(biggest - smallest - 2 * K, 0);
    }
};
