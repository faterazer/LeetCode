#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message)
    {
        char cur = 'a';
        unordered_map<char, char> mapping;
        for (const char &c : key)
            if (c != ' ' && !mapping.count(c))
                mapping[c] = cur++;
        
        for (char &c : message)
            if (c != ' ')
                c = mapping[c];
        return message;
    }
};
