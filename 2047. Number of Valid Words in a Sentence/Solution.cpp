#include <regex>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int countValidWords(string sentence)
    {
        istringstream in(sentence);
        string word;
        regex pattern("([a-z]+-[a-z]+|[a-z]*)[!\.,]?");
        int res = 0;
        while (in >> word) {
            if (regex_match(word, pattern))
                res++;
        }
        return res;
    }
};
