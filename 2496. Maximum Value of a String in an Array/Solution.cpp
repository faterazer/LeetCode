#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {
        int res = 0;
        for (const string &s : strs)
        {
            if (any_of(s.begin(), s.end(), ::isalpha))
                res = max(res, static_cast<int>(s.size()));
            else
                res = max(res, stoi(s));
        }
        return res;
    }
};
