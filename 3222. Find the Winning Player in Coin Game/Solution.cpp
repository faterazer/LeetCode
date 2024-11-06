#include <string>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y)
    {
        return min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
};
