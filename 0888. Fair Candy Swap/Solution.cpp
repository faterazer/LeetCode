#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> setB(B.begin(), B.end());
        for (const int &x : A)
            if (setB.count(x - diff))
                return {x, x - diff};
        return {};
    }
};
