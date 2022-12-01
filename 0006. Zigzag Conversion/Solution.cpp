#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows)
            return s;

        int n = s.size();
        string res;
        for (int i = 0, a = 2 * numRows - 2, b = 0; i < numRows; i++, a -= 2, b += 2) {
            int j = i;
            res.push_back(s[j]);
            while (j < n) {
                if (a > 0 && j + a < n)
                    res.push_back(s[j + a]);
                j += a;
                if (b > 0 && j + b < n)
                    res.push_back(s[j + b]);
                j += b;
            }
        }
        return res;
    }
};
