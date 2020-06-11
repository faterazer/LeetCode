#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars);
};

int Solution::compress(vector<char> &chars)
{
    int lasti = 0, i = 0, n = chars.size();
    while (i < n) {
        char ch = chars[i];
        int count = 0;
        while (i < n && chars[i] == ch) {
            i++;
            count++;
        }
        chars[lasti++] = ch;
        if (count > 1) {
            int j = lasti;
            while (count > 0) {
                chars[lasti++] = count % 10 + '0';
                count /= 10;
            }
            reverse(chars.begin() + j, chars.begin() + lasti);
        }
    }
    return lasti;
}
