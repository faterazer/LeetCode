#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        vector<vector<string>> groups(BUSINESS_LINE_TO_CATEGORY.size());
        int n = code.size();
        for (int i = 0; i < n; ++i)
            if (BUSINESS_LINE_TO_CATEGORY.contains(businessLine[i]) && is_valid(code[i]) && isActive[i])
                groups[BUSINESS_LINE_TO_CATEGORY.at(businessLine[i])].emplace_back(code[i]);

        vector<string> results;
        for (vector<string>& g : groups) {
            ranges::sort(g);
            results.insert(results.end(), g.begin(), g.end());
        }
        return results;
    }

private:
    bool is_valid(const string& s)
    {
        for (char c : s)
            if (c != '_' && !isalnum(c))
                return false;
        return !s.empty();
    }

    const unordered_map<string, int> BUSINESS_LINE_TO_CATEGORY { { "electronics", 0 }, { "grocery", 1 }, { "pharmacy", 2 }, { "restaurant", 3 } };
};
