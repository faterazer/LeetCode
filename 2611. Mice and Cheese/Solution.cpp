#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
    {
        int res = 0;
        for (size_t i = 0; i < reward1.size(); i++) {
            reward1[i] -= reward2[i];
            res += reward2[i];
        }
        nth_element(reward1.begin(), reward1.begin() + k, reward1.end(), greater<int>());
        return accumulate(reward1.begin(), reward1.begin() + k, res);
    }
};
