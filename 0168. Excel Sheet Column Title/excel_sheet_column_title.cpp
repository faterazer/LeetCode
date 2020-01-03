#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    string convertToTitle_MK1(int n);
    string convertToTitle_MK2(int n);
};

string Solution::convertToTitle_MK1(int n)
{
    string ret;
    while (n) {
        n--;
        ret.push_back(n % 26 + 'A');
        n /= 26;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string Solution::convertToTitle_MK2(int n)
{
    return n ? convertToTitle_MK2((n - 1) / 26) + char((n - 1) % 26 + 'A') : "";
}
