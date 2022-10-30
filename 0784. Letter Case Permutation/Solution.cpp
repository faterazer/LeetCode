#include <cctype>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s)
    {
        queue<string> Q;
        Q.emplace("");
        for (const char &c : s) {
            int size = Q.size();
            while (size--) {
                string ss = Q.front();
                Q.pop();
                if (!isalpha(c))
                    Q.emplace(ss + c);
                else {
                    Q.emplace(ss + static_cast<char>(tolower(c)));
                    Q.emplace(ss + static_cast<char>(toupper(c)));
                }
            }
        }
        vector<string> res;
        while (!Q.empty()) {
            res.emplace_back(Q.front());
            Q.pop();
        }
        return res;
    }
};
