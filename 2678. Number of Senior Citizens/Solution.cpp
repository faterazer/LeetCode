#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        int res = 0;
        for (const string& s : details)
            if (stoi(s.substr(11, 2)) > 60)
                ++res;
        return res;
    }
};
