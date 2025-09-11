#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    string sortVowels(string s)
    {
        string vowels;
        for (size_t i = 0; i < s.size(); ++i)
            if (isVowel(s[i]))
                vowels.push_back(s[i]);
        ranges::sort(vowels);
        for (size_t i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(s[i]))
                s[i] = vowels[j++];
        return s;
    }

private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
