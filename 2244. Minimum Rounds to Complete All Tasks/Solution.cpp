#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        unordered_map<int, int> cnt;
        for (int task : tasks)
            cnt[task]++;
        
        int res = 0;
        for (auto &[_, v] : cnt) {
            if (v == 1)
                return -1;
            res += (v + 2) / 3;
        }
        return res;
    }
};
