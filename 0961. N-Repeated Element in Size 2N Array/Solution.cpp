#include <random>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes_MK1(vector<int>& A)
    {
        for (size_t i = 2; i < A.size(); i++)
            if (A[i] == A[i - 1] || A[i] == A[i - 2])
                return A[i];
        return A[0];
    }

    int repeatedNTimes_MK2(vector<int>& A)
    {
        default_random_engine e;
        uniform_int_distribution<unsigned> dis(0, A.size() - 1);
        for (int i = 0; i < 10; ++i) {
            int x = dis(e), y = dis(e);
            if (x != y && A[x] == A[y])
                return A[x];
        }
        return repeatedNTimes_MK1(A);
    }
};
