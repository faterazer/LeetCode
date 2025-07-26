#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = 0;
                    break;
                }
            }
            if (j == n)
                ++ans;
        }
        return ans;
    }
};
