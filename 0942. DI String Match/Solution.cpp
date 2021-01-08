#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int l = 0, r = S.size();
        vector<int> res(S.size() + 1);
        size_t idx = 0;
        for (const char &ch : S)
            res[idx++] = ch == 'I' ? l++ : r--;
        res[idx] = l;
        return res;
    }
};
