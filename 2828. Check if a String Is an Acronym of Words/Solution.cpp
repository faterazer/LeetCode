#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s)
    {
        if (words.size() != s.size())
            return false;

        int n = words.size();
        for (int i = 0; i < n; i++)
            if (words[i][0] != s[i])
                return false;
        return true;
    }
};
