#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> st;
        for (const vector<string> &path : paths)
            st.emplace(path[0]);
        for (const vector<string> &path : paths)
            if (!st.count(path[1]))
                return path[1];
        return "";
    }
};
