#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end()), res = st.size();
        for (int i = 1; i * 3 <= max; i++) {
            if (st.count(i))
                continue;
            int g = 0;
            for (int j = 2 * i; j <= max && g != i; j += i)
                if (st.count(j))
                    g = gcd(g, j);
            if (g == i)
                ++res;
        }
        return res;
    }
};
