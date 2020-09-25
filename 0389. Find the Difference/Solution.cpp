#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    char findTheDifference_MK1(string s, string t); // 位运算
    char findTheDifference_MK2(string s, string t); // 哈希
};

char Solution::findTheDifference_MK1(string s, string t)
{
    char letter = 0;
    for (const char &c : s)
        letter ^= c;
    for (const char &c : t)
        letter ^= c;
    return letter;
}

char Solution::findTheDifference_MK2(string s, string t)
{
    vector<int> counter(26);
    for (const char &c : s)
        counter[c - 'a']++;
    for (const char &c : t)
        if (counter[c - 'a'] == 0)
            return c;
        else
            counter[c - 'a']--;
    return '\0';
}
