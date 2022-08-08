#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s)
    {
        if (s.size() <= 2)
            return s;

        int cnt = 0, i = 0;
        vector<string> subs;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1')
                ++cnt;
            else {
                --cnt;
                if (cnt == 0) {
                    subs.emplace_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
                    i = j + 1;
                }
            }
        }

        sort(subs.begin(), subs.end(), greater<string>());
        string res;
        for (const string& ss : subs)
            res += ss;
        return res;
    }
};
