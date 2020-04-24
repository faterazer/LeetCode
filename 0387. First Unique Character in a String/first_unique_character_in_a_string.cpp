#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s);
};

int Solution::firstUniqChar(string s)
{
    vector<int> counter(26);
    for (const char &c : s)
        counter[c - 'a']++;
    for (size_t i = 0; i < s.size(); i++)
        if (counter[s[i] - 'a'] == 1)
            return i;
    return -1;
}
