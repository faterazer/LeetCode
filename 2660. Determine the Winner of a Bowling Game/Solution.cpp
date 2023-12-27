#include <vector>
using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2)
    {
        int score1 = cal_score(player1), score2 = cal_score(player2);
        if (score1 > score2)
            return 1;
        else if (score1 < score2)
            return 2;
        else
            return 0;
    }

private:
    int cal_score(vector<int>& player)
    {
        int res = 0;
        int pre1 = 0, pre2 = 0;
        for (size_t i = 0; i < player.size(); i++) {
            res += pre1 == 10 || pre2 == 10 ? 2 * player[i] : player[i];
            pre1 = pre2;
            pre2 = player[i];
        }
        return res;
    }
};
