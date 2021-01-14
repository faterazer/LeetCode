#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        vector<bool> res;
        int n = 0;
        for (const int &bit : A) {
            n = (n * 2 + bit) % 5;
            res.emplace_back(n == 0);
               
        }
        return res;
    }
};
