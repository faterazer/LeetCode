#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;

        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                res.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }

private:
    bool isPalindrome(const string& s, int start, int end)
    {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }
};
