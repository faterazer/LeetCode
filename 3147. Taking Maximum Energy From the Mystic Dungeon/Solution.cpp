#include <vector>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k)
    {
        int ans = INT_MIN, n = energy.size();
        for (int i = 0; i < k; ++i) {
            int suf_sum = 0;
            for (int j = n - 1 - i; j >= 0; j -= k) {
                suf_sum += energy[j];
                ans = max(ans, suf_sum);
            }
        }
        return ans;
    }
};
