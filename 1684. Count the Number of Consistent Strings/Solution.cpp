#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int table[26] = {0};
        int res = words.size();
        for (const char &c : allowed)
            table[c - 'a'] = 1;
        for (const string &w : words) {
            for (const char &c : w) {
                if (!table[c - 'a']) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};
