#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        ranges::sort(folder);
        vector<string> ans{folder[0]};
        for (size_t i = 1; i < folder.size(); ++i) {
            string& s = folder[i];
            string& last = ans.back();
            if (!s.starts_with(last) || s[last.size()] != '/')
                ans.emplace_back(s);
        }
        return ans;
    }
};
