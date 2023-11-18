#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums)
    {
        int res = -1;
        unordered_map<int, int> dict;
        for (int x : nums) {
            int d = digits_sum(x);
            if (dict.contains(d))
                res = max(res, x + dict[d]);
            dict[d] = max(dict[d], x);
        }
        return res;
    }

private:
    int digits_sum(int x)
    {
        int res = 0;
        for (; x; x /= 10)
            res += x % 10;
        return res;
    }
};
