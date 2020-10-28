#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> umap;
        for (const int &n : arr)
            umap[n]++;
        unordered_set<int> uset;
        for (const auto &it : umap) {
            if (uset.count(it.second))
                return false;
            uset.insert(it.second);
        }
        return true;
    }
};
