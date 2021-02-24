#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res(n);
        for (int i = 0; i < n - 1; i++)
            res[i] = i + 1;
        res.back() = n * (n - 1) / 2;
        return res;
    }
};
