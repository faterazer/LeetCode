#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestPerimeter_MK1(vector<int> &A)
    {
        sort(A.rbegin(), A.rend());
        for (size_t i = 2; i < A.size(); i++)
            if (A[i - 2] < A[i - 1] + A[i])
                return A[i - 2] + A[i - 1] + A[i];
        return 0;
    }

    int largestPerimeter_MK2(vector<int> &A)
    {
        int *beg = A.data(), N = A.size();
        make_heap(beg, beg + N);
        pop_heap(beg, beg + N--);
        pop_heap(beg, beg + N--);
        while (N > 0) {
            pop_heap(beg, beg + N--);
            if (A[N] + A[N + 1] > A[N + 2])
                return A[N] + A[N + 1] + A[N + 2];
        }
        return 0;
    }
};
