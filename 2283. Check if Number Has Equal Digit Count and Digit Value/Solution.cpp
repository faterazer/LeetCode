#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool digitCount(string num)
    {
        unordered_map<int, int> cnt;
        for (const char &c : num)
            ++cnt[c - '0'];
        for (size_t i = 0; i < num.size(); i++)
            if (num[i] - '0' != cnt[i])
                return false;
        return true;
    }
};
