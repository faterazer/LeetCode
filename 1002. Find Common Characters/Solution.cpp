#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<int> hash_table(26, INT_MAX);
        vector<int> hash_buff(26, 0);
        for (const string &s : A) {
            fill(hash_buff.begin(), hash_buff.end(), 0);
            for (const char &ch : s)
                hash_buff[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                hash_table[i] = min(hash_table[i], hash_buff[i]);
        }
        vector<string> ret;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < hash_table[i]; j++)
                ret.emplace_back(1, 'a' + i);
        }
        return ret;
    }
};
