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
    if (haystack.size() < needle.size())
        return -1;
        
    for (size_t i = 0; i != (haystack.size() - needle.size() + 1); i++)
        if (haystack.substr(i, needle.size()) == needle)
            return i;
    return -1;
}

int main()
{
    string haystack = "aaaaa", needle = "";
    cout << Solution().strStr(haystack, needle) << endl;
    return 0;
}