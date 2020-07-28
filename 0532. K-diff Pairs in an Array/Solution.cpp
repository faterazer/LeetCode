#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int ans = 0;
        if (k < 0)
            return ans;
        unordered_map<int, int> umap;
        for (const int &n : nums) {
            umap[n]++;
            if (k == 0)
                ans += umap[n] == 2;
            else if (umap[n] == 1)
                ans += umap.count(n - k) + umap.count(n + k);
        }
        return ans;
    }
};
