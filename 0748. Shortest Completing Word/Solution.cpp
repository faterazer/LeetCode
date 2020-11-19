#include <algorithm>
#include <cctype>
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        string res(16, 0);   // words[i] 最长为 15
        int hashTable[26] = {0};
        for (const char &ch : licensePlate)
            if (isalpha(ch))
                hashTable[tolower(ch) - 'a']++;
        int counter[26] = {0};
        for (const string word : words) {
            if (word.size() >= res.size())
                continue;
            fill(begin(counter), end(counter), 0);
            for (const char &ch : word)
                counter[ch - 'a']++;
            int i = 0;
            while (i < 26 && counter[i] >= hashTable[i])
                i++;
            if (i == 26)
                res = word;
        }
        return res;
    }
};
