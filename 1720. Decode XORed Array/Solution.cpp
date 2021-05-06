#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> res(1, first);
        for (const int &x : encoded)
            res.emplace_back(res.back() ^ x);
        return res;
    }
};
