#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int cnt[26] = { 0 };
        for (char c : tasks)
            cnt[c - 'A']++;

        int max_val = *max_element(begin(cnt), end(cnt));
        int max_cnt = count(begin(cnt), end(cnt), max_val);
        return max(max_val + (max_val - 1) * n - 1 + max_cnt, static_cast<int>(tasks.size()));
    }
};
