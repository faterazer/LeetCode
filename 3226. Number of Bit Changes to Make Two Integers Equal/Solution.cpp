#include <bit>
using namespace std;

class Solution {
public:
    int minChanges(unsigned n, unsigned k)
    {
        return (n | k) == n ? popcount(n ^ k) : -1;
    }
};
