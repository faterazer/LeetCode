#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours)
    {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0)
                res = i + 1;
            else {
                if (!seen.count(score))
                    seen[score] = i;
                if (seen.count(score - 1))
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
};
