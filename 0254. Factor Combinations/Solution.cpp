#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n)
    {
        vector<vector<int>> res;
        vector<int> buff;
        helper(n, res, buff);
        return res;
    }

private:
    void helper(int n, vector<vector<int>>& res, vector<int>& buff)
    {
        for (int i = buff.empty() ? 2 : buff.back(); i <= n / i; i++) {
            if (n % i == 0) {
                buff.emplace_back(i);
                buff.emplace_back(n / i);
                res.emplace_back(buff);
                buff.pop_back();
                helper(n / i, res, buff);
                buff.pop_back();
            }
        }
    }
};
