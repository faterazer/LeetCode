#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle)
{
    return haystack.find(needle);
}

int main()
{
    string haystack = "aaaaa", needle = "";
    cout << Solution().strStr(haystack, needle) << endl;
    return 0;
}