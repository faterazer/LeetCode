#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        int n = expression.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n));
        compute(expression, 0, n - 1, memo);
        return memo[0][n - 1];
    }

private:
    vector<int> compute(const string& expression, int l, int r, vector<vector<vector<int>>>& memo)
    {
        if (!memo[l][r].empty())
            return memo[l][r];
        for (int i = l; i <= r; ++i) {
            if (isdigit(expression[i]))
                continue;
            vector<int> left = compute(expression, l, i - 1, memo);
            vector<int> right = compute(expression, i + 1, r, memo);
            for (const int& a : left) {
                for (const int& b : right) {
                    if (expression[i] == '+')
                        memo[l][r].emplace_back(a + b);
                    else if (expression[i] == '-')
                        memo[l][r].emplace_back(a - b);
                    else
                        memo[l][r].emplace_back(a * b);
                }
            }
        }
        if (memo[l][r].empty())
            memo[l][r] = vector<int>(1, stoi(expression.substr(l, r - l + 1)));
        return memo[l][r];
    }
};
