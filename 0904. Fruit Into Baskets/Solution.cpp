#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        unordered_map<int, int> cnt;
        int i, j, n = fruits.size();
        for (i = 0, j = 0; j < n; j++) {
            ++cnt[fruits[j]];
            if (cnt.size() > 2) {
                if (--cnt[fruits[i]] == 0)
                    cnt.erase(fruits[i]);
                ++i;
            }
        }
        return j - i;
    }
};
