#include <vector>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands)
    {
        int i = 0, j = 0;
        for (const string& s : commands) {
            switch (s[0]) {
            case 'U':
                --i;
                break;
            case 'D':
                ++i;
                break;
            case 'L':
                --j;
                break;
            default:
                ++j;
            }
        }
        return i * n + j;
    }
};
