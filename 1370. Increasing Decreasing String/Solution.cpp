#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        map<char, int> mp;
        for (const char &ch : s)
            mp[ch]++;

        string res;
        for (int i = 0; res.size() != s.size(); i++) {
            if (i % 2 == 0)
                ascendAppend(res, mp);
            else
                descendAppend(res, mp);
        }
        return res;
    }

private:
    void ascendAppend(string &s, map<char, int> &mp)
    {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) {
                s += it->first;
                it->second--;
            }
        }
    }

    void descendAppend(string &s, map<char, int> &mp)
    {
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            if (it->second > 0) {
                s += it->first;
                it->second--;
            }
        }
    }
};
