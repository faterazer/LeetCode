#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights)
    {
        string result;
        result.reserve(words.size());
        for (const string& word: words) {
            int weight = 0;
            for (char c : word)
                weight += weights[c - 'a'];
            result.push_back('z' - weight % 26);
        }
        return result;
    }
};
