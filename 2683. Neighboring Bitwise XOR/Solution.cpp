#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        return reduce(derived.begin(), derived.end(), 0, bit_xor()) == 0;
    }
};
