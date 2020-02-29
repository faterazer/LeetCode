#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str);
};

bool Solution::wordPattern(string pattern, string str)
{
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;
    int i = 0, n = pattern.size();
    istringstream in(str);
    for (string word; in >> word; i++) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}
