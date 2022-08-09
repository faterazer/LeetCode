#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        int P = 1000000007;
        unordered_map<int, long long> cnt;
        for (const int& e : arr)
            cnt[e] = 1;
        sort(arr.begin(), arr.end());
        for (size_t i = 1; i < arr.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (arr[i] % arr[j] != 0)
                    continue;
                int a = arr[j], b = arr[i] / arr[j];
                if (!cnt.count(b))
                    continue;
                cnt[arr[i]] = (cnt[arr[i]] + cnt[a] * cnt[b]) % P;
            }
        }

        int res = 0;
        for (const auto& it : cnt)
            res = (res + it.second) % P;
        return res;
    }
};
