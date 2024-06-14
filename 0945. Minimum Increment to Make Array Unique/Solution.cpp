#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique_MK1(vector<int> &A);
    int minIncrementForUnique_MK2(vector<int> &A);
};

int Solution::minIncrementForUnique_MK1(vector<int> &A)
{
    vector<int> buff(80001, 0);
    for (const int &n : A)
        buff[n]++;
    
    int ret = 0;
    int len = A.size();
    for (size_t i = 0; i < buff.size() - 1 && len; i++) {
        if (buff[i] > 1) {
            ret += buff[i] - 1;
            buff[i + 1] += buff[i] - 1;
            len--;
        }
        else if (buff[i] == 1)
            len--;
    }
    return ret;
}

int Solution::minIncrementForUnique_MK2(vector<int> &A)
{
    sort(A.begin(), A.end());
    int ret = 0;
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] <= A[i - 1]) {
            ret += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return ret;
}
