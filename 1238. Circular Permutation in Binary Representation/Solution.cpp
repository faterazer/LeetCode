#include <vector>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> res;
        for (int i = 0; i < 1 << n; i++)
            res.emplace_back(i ^ (i >> 1) ^ start);
        return res;
    }
};
