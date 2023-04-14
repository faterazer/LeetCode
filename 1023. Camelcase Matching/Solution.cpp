#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern)
    {
        vector<bool> res;
        for (const string& query : queries) {
            int i = 0, j = 0;
            for (; i < query.size(); i++) {
                if (j <= pattern.size() && query[i] == pattern[j])
                    j++;
                else if (isupper(query[i]))
                    break;
            }
            res.emplace_back(i == query.size() && j == pattern.size());
        }
        return res;
    }
};
