#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> res;
        string buff1, buff2, word;
        istringstream in(text);
        while (in >> word) {
            if (buff1 == first && buff2 == second)
                res.emplace_back(word);
            buff1 = buff2;
            buff2 = word;
        }
        return res;
    }
};
