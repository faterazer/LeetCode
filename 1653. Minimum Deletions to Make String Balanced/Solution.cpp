#include <string>
using namespace std;

class Solution {
public:
    int minimumDeletions_MK2(string s)
    {
        int del = 0;
        for (const char& c : s)
            del += c == 'a';

        int res = del;
        for (const char& c : s) {
            del += 2 * (c == 'b') - 1;
            res = min(res, del);
        }
        return res;
    }

    int minimumDeletions_MK2(string s)
    {
        int res = 0, cnt_b = 0;
        for (const char& c : s) {
            if (c == 'b')
                cnt_b++;
            else
                res = min(res + 1, cnt_b);
        }
        return res;
    }
};
