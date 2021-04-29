#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> res(code.size(), 0);
        if (k == 0)
            return res;
        int n = code.size(), bg = 1, ed = k, sum = 0;
        if (k < 0) {
            bg = n + k;
            ed = n - 1;
        }
        for (int i = bg; i <= ed; i++)
            sum += code[i];
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            sum -= code[(bg++) % n];
            sum += code[(++ed) % n];
        }
        return res;
    }
};
