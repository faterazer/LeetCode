#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        word.push_back('a');
        unordered_set<string> nset{""};
        for (size_t i = 0, j = 0; j < word.size(); j++) {
            if (isdigit(word[j])) {
                if (i < j && word[i] == '0')
                    i++;
            } else {
                nset.insert(word.substr(i, j - i));
                i = j + 1;
            }
        }
        return nset.size() - 1;
    }
};
