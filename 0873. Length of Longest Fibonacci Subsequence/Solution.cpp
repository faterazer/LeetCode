#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        unordered_map<int, int> indices;
        for (size_t i = 0; i < arr.size(); ++i)
            indices[arr[i]] = i;

        int res = 0;
        unordered_map<int, int> dp;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int need = arr[i] - arr[j];
                if (need > arr[j] && indices.count(need)) {
                    int k = indices[need];
                    dp[k * 1000 + i] = dp[j * 1000 + k] + 1;
                    res = max(res, dp[k * 1000 + i] + 2);
                }
            }
        }
        return res > 2 ? res : 0;
    }
};
