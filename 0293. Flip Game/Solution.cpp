#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState)
    {
        vector<string> res;
        for (size_t i = 1; i < currentState.size(); i++) {
            if (currentState[i - 1] == '+' && currentState[i] == '+') {
                res.emplace_back(currentState);
                res.back()[i - 1] = res.back()[i] = '-';
            }
        }
        return res;
    }
};
