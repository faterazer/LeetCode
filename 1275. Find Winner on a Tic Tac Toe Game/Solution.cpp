#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<int> row(3, 0), col(3, 0), dia(2, 0);
        for (size_t i = 0; i < moves.size(); i++) {
            vector<int> &m(moves[i]);
            if (i % 2 == 0) {
                if (++row[m[0]] == 3 || ++col[m[1]] == 3 || (m[0] == m[1] && ++dia[0] == 3) || (m[0] + m[1] == 2 && ++dia[1] == 3))
                    return "A";
            }
            else {
                if (--row[m[0]] == -3 || --col[m[1]] == -3 || (m[0] == m[1] && --dia[0] == -3) || (m[0] + m[1] == 2 && --dia[1] == -3))
                    return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
