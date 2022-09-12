#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int res = 0, score = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++score);
            } else if (score > 0) {
                score -= 1;
                power += tokens[j--];
            } else
                break;
        }
        return res;
    }
};
