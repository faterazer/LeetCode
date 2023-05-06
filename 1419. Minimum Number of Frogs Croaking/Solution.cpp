#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        string croak = "croak";
        int cnt[5] = { 0 }, res = 0, frogs = 0;
        for (const char& ch : croakOfFrogs) {
            int i = croak.find(ch);
            ++cnt[i];
            if (i == 0)
                res = max(res, ++frogs);
            else if (--cnt[i - 1] < 0)
                return -1;
            else if (i == 4)
                --frogs;
        }
        return frogs == 0 ? res : -1;
    }
};
