#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words)
    {
        unordered_map<unsigned, int> cnt;
        int ans = 0;
        for (const string& word : words) {
            unsigned key = 0;
            for (char c : word)
                key |= 1 << (c - 'a');
            ans += cnt[key]++;
        }
        return ans;
    }
};
