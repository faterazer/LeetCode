#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size(), max_idx = n - 1, a = -1, b;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[max_idx])
                max_idx = i;
            else if (s[i] < s[max_idx]) {
                a = i;
                b = max_idx;
            }
        }
        if (a == -1)
            return num;
        swap(s[a], s[b]);
        return stoi(s);
    }
};
