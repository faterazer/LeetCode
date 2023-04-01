#include <algorithm>
#include <regex>
#include <string>
using namespace std;

class Solution {
public:
    string maskPII(string s)
    {
        size_t at = s.find("@");
        if (at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }

private:
    vector<string> country { "", "+*-", "+**-", "+***-" };
};
