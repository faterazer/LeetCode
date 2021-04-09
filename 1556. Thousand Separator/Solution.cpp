#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string res;
        int cnt = 0;
        do {
            if (++cnt == 4) {
                res.push_back('.');
                cnt = 1;
            }
            res.push_back(n % 10 + '0');
            n /= 10;
        } while (n);
        reverse(res.begin(), res.end());
        return res;
    }
};
