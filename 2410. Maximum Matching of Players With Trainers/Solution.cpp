#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        ranges::sort(players);
        ranges::sort(trainers);

        size_t i = 0, j = 0;;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j])
                ++i;
            ++j;
        }
        return i;
    }
};
