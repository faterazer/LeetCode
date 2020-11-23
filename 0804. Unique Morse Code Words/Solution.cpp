#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                          "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> uset;
        for (const string &word : words) {
            string code;
            for (const char &ch : word)
                code += morse[ch - 'a'];
            uset.insert(code);
        }
        return uset.size();
    }
};
