#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr)
    {
        int res = INT_MIN, f0 = INT_MIN / 2, f1 = INT_MIN / 2;
        for (int x : arr) {
            f1 = max(f1 + x, f0);
            f0 = max(f0, 0) + x;
            res = max(res, max(f0, f1));
        }
        return res;
    }
};
