#include <string>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (const char &move : moves) {
            switch (move) {
                case 'U':
                    x++;
                    break;
                case 'D':
                    x--;
                    break;
                case 'R':
                    y++;
                    break;
                case 'L':
                    y--;
                    break;
            }
        }
        return x== 0 && y == 0;
    }
};
