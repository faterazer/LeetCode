#include <bit>
using namespace std;

class Solution {
public:
    char kthCharacter(int k)
    {
        return 'a' + popcount(static_cast<unsigned>(k - 1));
    }
};
