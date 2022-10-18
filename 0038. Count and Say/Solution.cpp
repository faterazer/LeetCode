#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string s;
            int last = 0, j = 0;
            while (j < res.size()) {
                while (j < res.size() && res[j] == res[last])
                    ++j;
                s += to_string(j - last) + res[last];
                last = j;
            }
            res = s;
        }
        return res;
    }
};
