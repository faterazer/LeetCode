#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> table { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        queue<string> Q;
        Q.emplace("");
        for (const char& d : digits) {
            int n = Q.size();
            for (int i = 0; i < n; ++i) {
                string s = Q.front();
                Q.pop();
                string candidates = table[d - '0'];
                for (const char& c : candidates)
                    Q.emplace(s + string(1, c));
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
