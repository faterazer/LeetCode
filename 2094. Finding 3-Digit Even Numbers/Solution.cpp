#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        unordered_map<int, int> cnt;
        for (int d : digits)
            ++cnt[d];
        vector<int> ans;
        for (int k = 0; k <= 8; k += 2) {
            if (cnt[k] == 0)
                continue;
            --cnt[k];
            for (auto [i, ci] : cnt) {
                if (i == 0 || ci == 0)
                    continue;
                for (auto [j, cj] : cnt)
                    if ((i != j && cj) || cj > 1)
                        ans.emplace_back(i * 100 + j * 10 + k);
            }
            ++cnt[k];
        }
        ranges::sort(ans);
        return ans;
    }
};
