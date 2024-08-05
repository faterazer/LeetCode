#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> cnt;
        for (const string& s : arr)
            ++cnt[s];
        for (const string& s : arr)
            if (cnt[s] == 1 && --k == 0)
                return s;
        return "";
    }
};
