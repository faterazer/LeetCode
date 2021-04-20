#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr_MK1(string haystack, string needle)
    {
        return haystack.find(needle);
    }

    int strStr_MK2(string haystack, string needle)
    {
        for (size_t i = 0; ; i++) {
            for (size_t j = 0; ; j++) {
                if (j == needle.size())
                    return i;
                if (i + j == haystack.size())
                    return -1;
                if (haystack[i + j] != needle[j])
                    break;
            }
        }
        return -1;
    }

    // KMP
    int strStr_MK3(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        vector<int> next(needle.size());
        for (size_t i = 1, j = 0; i < needle.size(); i++) {
            while (j > 0 && needle[i] != needle[j])
                j = next[j - 1];
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }
        for (size_t i = 0, j = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};
