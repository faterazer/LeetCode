#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        unordered_set<string> seen;
        sort(folder.begin(), folder.end(), [](const string& left, const string& right) {
            return left.size() < right.size();
        });

        vector<string> res;
        for (const string& f : folder) {
            bool check = true;
            for (size_t i = 2; i < f.size(); i++) {
                if (f[i] == '/' && seen.count(f.substr(0, i))) {
                    check = false;
                    break;
                }
            }
            if (check)
                res.emplace_back(f);
            seen.emplace(f);
        }
        return res;
    }
};
