#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s);
};

int Solution::longestPalindrome(string s)
{
    unordered_map<char, int> counter;
    for (const char &ch : s)
        counter[ch]++;

    int len = 0;
    for (const auto &it : counter)
        len += it.second - (it.second & 1);
    return len < s.size() ? len + 1 : len;
}
