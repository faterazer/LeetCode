#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2);
};

string Solution::addStrings(string num1, string num2)
{
    string res;
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--) {
        int a = i < 0 ? 0 : num1[i] - '0';
        int b = j < 0 ? 0 : num2[j] - '0';
        carry += a + b;
        res.push_back(carry % 10 + '0');
        carry /= 10;
    }
    if (carry)
        res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}
