#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_set<int> prefix_set;
        for (int x : arr1) {
            while (!prefix_set.contains(x)) {
                prefix_set.insert(x);
                x /= 10;
            }
        }

        int ans = 0;
        for (int x : arr2) {
            while (!prefix_set.contains(x))
                x /= 10;
            ans = max(ans, x);
        }
        return ans ? to_string(ans).size() : 0;
    }
};
