#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars);
};

int Solution::countCharacters(vector<string> &words, string chars)
{
    vector<int> char_table(26, 0);
    for (const char &ch : chars)
        char_table[ch - 'a']++;

    vector<int> tmp_table;
    int len = 0;
    for (const string &word : words) {
        tmp_table = char_table;
        len += word.size();
        for (const char &ch : word) {
            tmp_table[ch - 'a']--;
            if (tmp_table[ch - 'a'] < 0) {
                len -= word.size();
                break;
            }
        }
    }
    return len;
}
