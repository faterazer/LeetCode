#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A);
};

bool Solution::canThreePartsEqualSum(vector<int> &A)
{
    int total = accumulate(A.begin(), A.end(), 0);
    if (total % 3)
        return false;
    int sum = 0, count = 0, target = total / 3, climit = target != 0 ? 2 : 3;
    for (size_t i = 0; i < A.size() && count < climit; i++) {
        sum += A[i];
        if (sum == target) {
            sum = 0;
            count++;
        }
    }
    return count == climit;
}
