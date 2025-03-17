#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(const string& s)
    {
        int n = s.size();
        vector<vector<int>> is_palindrome(n, vector<int>(n, 1));
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i)
                is_palindrome[i][j] = (s[i] == s[j]) && (j - i < 3 || is_palindrome[i + 1][j - 1]);

        vector<vector<string>> ans;
        vector<string> path;

        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            for (int j = i; j < n; ++j) {
                if (is_palindrome[i][j]) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};
