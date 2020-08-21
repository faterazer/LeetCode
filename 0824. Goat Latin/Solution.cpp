#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string toGoatLatin(string S)
    {
        istringstream in(S);
        string word, ret;
        int index = 1;
        while (in >> word) {
            if (vowels.count(word[0]))
                ret += word;
            else
                ret += word.substr(1) + word[0];
            ret += "ma" + string(index++, 'a') + " ";
        }
        ret.pop_back();
        return ret;
    }

private:
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};
