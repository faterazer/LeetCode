#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A)
    {
        vector<bool> result;
        int n = 0;
        for (int bit : A) {
            n = (n << 1 | bit) % 5;
            result.emplace_back(n == 0);
        }
        return result;
    }
};
