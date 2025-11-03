#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends)
    {
        unordered_set<int> friend_set(friends.begin(), friends.end());
        vector<int> ans;
        ans.reserve(friends.size());
        for (int x : order)
            if (friend_set.contains(x))
                ans.emplace_back(x);
        return ans;
    }
};
