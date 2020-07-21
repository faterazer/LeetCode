#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b);
};

string Solution::addBinary(string a, string b)
{
    auto aiter = a.rbegin();
    auto biter = b.rbegin();
    int carry = 0;
    string ans = "";
    while (aiter != a.rend() || biter != b.rend() || carry == 1) {
        int adigit = 0, bdigit = 0;
        if (aiter != a.rend()) {
            adigit = *aiter == '1';
            aiter++;
        }
        if (biter != b.rend()) {
            bdigit = *biter == '1';
            biter++;
        }
        ans.push_back(adigit ^ bdigit ^ carry + '0');
        carry = (adigit + bdigit + carry) / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
