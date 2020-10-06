#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> scores;
        for (const string &op : ops) {
            if (op == "+") {
                int last1 = scores.back();
                int last2 = scores[scores.size() - 2];
                scores.emplace_back(last1 + last2);
            }
            else if (op == "D")
                scores.emplace_back(scores.back() * 2);
            else if (op == "C")
                scores.pop_back();
            else
                scores.emplace_back(stoi(op));
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
