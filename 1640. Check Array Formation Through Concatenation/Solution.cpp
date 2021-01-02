#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, int> n2piece;
        for (size_t i = 0; i < pieces.size(); i++)
            n2piece[pieces[i][0]] = i;
        for (size_t i = 0; i < arr.size();) {
            if (!n2piece.count(arr[i]))
                return false;
            vector<int> &p = pieces[n2piece[arr[i]]];
            for (size_t j = 0; j < p.size(); j++)
                if (arr[i++] != p[j])
                    return false;
        }
        return true;
    }
};
