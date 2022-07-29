#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        vector<int> side_lens {
            dist(p1, p2), dist(p1, p3), dist(p1, p4),
            dist(p2, p3), dist(p2, p4), dist(p3, p4)
        };
        sort(side_lens.begin(), side_lens.end());
        return side_lens[0] == side_lens[3] && side_lens[3] != side_lens[4] && side_lens[4] == side_lens[5];
    }

private:
    int dist(const vector<int>& p1, const vector<int>& p2)
    {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }
};
