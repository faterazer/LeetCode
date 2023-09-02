#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (size_t i = 0; i < res.size(); i++) {
            if (i & 1)
                res[i] = res[i - 1] + 1;
            else
                res[i] = res[i / 2];
        }
        return res;
    }
};
