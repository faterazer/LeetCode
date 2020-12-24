#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        unordered_map<string, int> ACnt, BCnt;
        istringstream in(A + " " + B);
        string word;
        while (in >> word)
            ACnt[word]++;
        vector<string> ret;
        for (const pair<string, int> &w : ACnt)
            if (w.second == 1)
                ret.emplace_back(w.first);
        return ret;
    }
};
