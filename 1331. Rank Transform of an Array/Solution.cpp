#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> ump;
        int n = 1;
        for (auto it = st.begin(); it != st.end(); it++)
            ump[*it] = n++;
        vector<int> res(arr.size());
        for (size_t i = 0; i < arr.size(); i++)
            res[i] = ump[arr[i]];
        return res;
    }
};
