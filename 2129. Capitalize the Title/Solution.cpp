#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title)
    {
        string res, s;
        istringstream in(title);
        while (in >> s) {
            if (s.size() <= 2)
                transform(s.begin(), s.end(), s.begin(), ::tolower);
            else {
                s[0] = toupper(s[0]);
                transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
            }
            res += s + ' ';
        }
        res.pop_back();
        return res;
    }
};
