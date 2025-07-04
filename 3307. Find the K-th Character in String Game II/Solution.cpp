#include <bit>
#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations)
    {
        --k;
        int m = bit_width(static_cast<unsigned long long>(k));
        int inc = 0;
        for (int i = 0; i < m; ++i)
            inc += k >> i & operations[i];
        return 'a' + inc % 26;
    }
};
