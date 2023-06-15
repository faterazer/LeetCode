#include <bitset>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
    {
        int pre_sum[s.size() + 1];
        pre_sum[0] = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int bit = 1 << (s[i] - 'a');
            pre_sum[i + 1] = pre_sum[i] ^ bit;
        }

        vector<bool> res;
        for (const vector<int>& query : queries) {
            int left = query[0], right = query[1], k = query[2];
            int cnt = bitset<32>((pre_sum[right + 1] ^ pre_sum[left])).count();
            res.emplace_back(cnt / 2 <= k);
        }
        return res;
    }
};
