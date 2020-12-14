#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> res(S.size(), 0);
        size_t lastC = S.find(C);
        for (size_t i = 0; i < lastC; i++)
            res[i] = lastC - i;
        for (size_t i = S.find(C, lastC + 1); i != string::npos; lastC = i, i = S.find(C, i + 1)) {
            for (size_t j = lastC + 1; j < i; j++)
                res[j] = min(j - lastC, i - j);
        }
        for (size_t i = lastC + 1; i < res.size(); i++)
            res[i] = i - lastC;
        return res;
    }
};
