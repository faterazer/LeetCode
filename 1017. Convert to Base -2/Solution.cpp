#include <string>
using namespace std;

class Solution {
public:
    string baseNeg2(int n)
    {
        string res = "";
        while (n) {
            res = to_string(n & 1) + res;
            n = -(n >> 1);
        }
        return res == "" ? "0" : res;
    }
};
