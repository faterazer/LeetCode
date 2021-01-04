#include <string>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int l = 0, r = S.size() - 1;
        while (l < r) {
            while (l < r && !isalpha(S[l]))
                l++;
            while (r > l && !isalpha(S[r]))
                r--;
            if (l < r)
                swap(S[l++], S[r--]);
        }
        return S;
    }
};
