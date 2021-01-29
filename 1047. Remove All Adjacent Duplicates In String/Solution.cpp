#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        for (const char &ch : S) {
            if (!res.empty() && res.back() == ch)
                res.pop_back();
            else
                res.push_back(ch);
        }
        return res;
    }
};
