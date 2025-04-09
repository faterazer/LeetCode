#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        unordered_set<int> st;
        for (int x : nums) {
            if (x < k)
                return -1;
            else if (x > k)
                st.emplace(x);
        }
        return st.size();
    }
};
