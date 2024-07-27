#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k)
    {
        for (char& c : s) {
            int d = min(c - 'a', 'z' - c + 1);
            if (d > k) {
                c -= k;
                break;
            }
            c = 'a';
            k -= d;
        }
        return s;
    }
};
