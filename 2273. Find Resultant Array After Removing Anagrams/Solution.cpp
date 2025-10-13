#include <array>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        vector<string> ans;
        array<int, 26> cnt1{};
        for (const string &word : words) {
            array<int, 26> cnt2{};
            for (char c : word)
                ++cnt2[c - 'a'];
            if (cnt1 != cnt2) {
                ans.emplace_back(word);
                cnt1 = cnt2;
            }
        }
        return ans;
    }
};
