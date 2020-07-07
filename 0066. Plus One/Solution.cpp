#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &);
    vector<int> plusOne_moreTricky(vector<int> &);
};

vector<int> Solution::plusOne(vector<int> &digits)
{
    vector<int> ans;
    int carry = 1;
    for (auto i = digits.crbegin(); i != digits.crend(); i++) {
        carry += *i;
        ans.emplace_back(carry % 10);
        carry /= 10;
    }
    if (carry)
        ans.emplace_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> Solution::plusOne_moreTricky(vector<int> &digits)
{
    for (int i = digits.size(); i--; digits[i] = 0)
        if (++digits[i] < 10)
            return digits;
    digits.front() = 1;
    digits.emplace_back(0);
    return digits;
}
