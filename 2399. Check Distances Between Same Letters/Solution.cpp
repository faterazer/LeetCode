#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance)
    {
        int last[26] = { 0 }, n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (last[c] && i - last[c] != distance[c])
                return false;
            last[c] = i + 1;
        }
        return true;
    }
};
