#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys)
    {
        int MOD = 1e9 + 7, n = pressedKeys.size() + 1;
        vector<int> f(pressedKeys.size() + 1, 0);
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            int m = pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9' ? 4 : 3;
            int j = i - 1;
            for (; j > 0 && i - j < m && pressedKeys[j - 1] == pressedKeys[i - 1]; --j)
                f[i] = (f[i] + f[j]) % MOD;
            f[i] = (f[i] + f[j]) % MOD;
        }
        return f.back();
    }
};
