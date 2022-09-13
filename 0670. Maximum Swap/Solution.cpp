#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int cnter[10] = { 0 }, n = s.size();
        for (int i = 0; i < n; ++i)
            cnter[s[i] - '0'] = i;
        for (size_t i = 0; i < s.size(); ++i) {
            int x = s[i] - '0';
            for (int j = 9; j > x; --j) {
                if (cnter[j] > i) {
                    swap(s[i], s[cnter[j]]);
                    return stoi(s);
                }
            }
        }
        return stoi(s);
    }
};
