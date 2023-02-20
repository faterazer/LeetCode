#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits)
    {
        if (unordered_set<char>(suits.begin(), suits.end()).size() == 1)
            return "Flush";

        unordered_map<int, int> cnt;
        for (const int& x : ranks)
            cnt[x]++;
        if (cnt.size() == 5)
            return "High Card";
        for (const auto& [_, val] : cnt)
            if (val > 2)
                return "Three of a Kind";
        return "Pair";
    }
};
