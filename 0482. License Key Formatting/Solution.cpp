#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string S, int K);
};

string Solution::licenseKeyFormatting(string S, int K)
{
    string ret;
    for (auto it = S.rbegin(); it != S.rend(); it++) {
        if (*it != '-') {
            if (ret.size() % (K + 1) == K)
                ret.push_back('-');
            ret.push_back(toupper(*it));
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
