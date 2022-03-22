#include <string>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int Alice_count = 0, Bob_count = 0;
        for (size_t i = 1; i < colors.size() - 1; ++i) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A')
                    Alice_count += 1;
                else
                    Bob_count += 1;
            }
        }
        return Alice_count > Bob_count;
    }
};
