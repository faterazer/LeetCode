#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> words1 = split(sentence1), words2 = split(sentence2);
        if (words1.size() < words2.size())
            swap(words1, words2);
        int i = 0, n1 = words1.size(), n2 = words2.size();
        while (i < n2 && words1[i] == words2[i])
            ++i;
        int k = n1, j = n2;
        while (j > i && words1[k - 1] == words2[j - 1]) {
            --k;
            --j;
        }
        return i == j;
    }

private:
    vector<string> split(const string& sentence)
    {
        vector<string> res;
        istringstream in(sentence);
        string s;
        while (in >> s)
            res.emplace_back(s);
        return res;
    }
};
