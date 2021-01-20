#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        reverse(A.begin(), A.end());
        for (size_t i = 0; i < A.size() && K; i++, K /= 10) {
            K += A[i];
            A[i] = K % 10;
        }
        for (; K; K /= 10)
            A.emplace_back(K % 10);
        reverse(A.begin(), A.end());
        return A;
    }
};
