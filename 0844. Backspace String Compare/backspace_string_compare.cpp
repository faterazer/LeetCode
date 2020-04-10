#include <string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T);
};

bool Solution::backspaceCompare(string S, string T)
{
    int i = S.size() - 1, j = T.size() - 1;
    int skip_s = 0, skip_t = 0;
    while (i >= 0 || j >= 0) {
        for (; i >= 0 && (S[i] == '#' || skip_s); i--) {
            if (S[i] == '#')
                skip_s++;
            else
                skip_s--;
        }
        for (; j >= 0 && (T[j] == '#' || skip_t); j--) {
            if (T[j] == '#')
                skip_t++;
            else
                skip_t--;
        }
        if ((i >= 0) != (j >= 0) || (i >= 0 && j >= 0 && S[i] != T[j]))
            return false;
        i--; j--;
    }
    return true;
}
