#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target)
    {
        vector<int> res;
        for (size_t i = 0; i < variables.size(); i++) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            if (pow(pow(a, b, 10), c, m) == target)
                res.emplace_back(i);
        }
        return res;
    }

private:
    int pow(int base, int exp, int mod)
    {
        int res = 1;
        while (exp) {
            if (exp & 1)
                res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }
};
