#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        make_heap(A.begin(), A.end(), greater<int>());
        for (int i = 0; i < K; i++) {
            pop_heap(A.begin(), A.end(), greater<int>());
            A.back() *= -1;
            push_heap(A.begin(), A.end(), greater<int>());
        }
        return accumulate(A.begin(), A.end(), 0);
    }
};
