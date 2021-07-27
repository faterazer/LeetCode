#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> cnter;
        for (const char &c : s)
            cnter[c]++;
        int last = cnter.cbegin()->second;
        for (auto it = cnter.cbegin(); it != cnter.cend(); it++)
            if (it->second != last)
                return false;
        return true;
    }
};
