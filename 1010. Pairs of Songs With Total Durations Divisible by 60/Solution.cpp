#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const int& t : time) {
            res += cnt[(60 - t % 60) % 60];
            cnt[t % 60]++;
        }
        return res;
    }
};
