#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        unordered_map<unsigned, size_t> cnt;
        for (size_t i = 0; i < words.size(); i++) {
            unsigned x = 0;
            for (char c : words[i])
                x |= 1 << (c - 'a');
            cnt[x] = max(cnt[x], words[i].size());
        }
        size_t res = 0;
        for (auto& [k1, v1] : cnt)
            for (auto& [k2, v2] : cnt)
                if ((k1 & k2) == 0)
                    res = max(v1 * v2, res);
        return res;
    }
};
