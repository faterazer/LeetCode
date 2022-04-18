#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res(n);
        for (int i = 0, x = 1; i < n; ++i, x = nextNum(x, n))
            res[i] = x;
        return res;
    }

private:
    int nextNum(int x, int limit)
    {
        if (x * 10 <= limit)
            return x * 10;
        while (x + 1 > limit || x % 10 == 9)
            x /= 10;
        return x + 1;
    }
};
