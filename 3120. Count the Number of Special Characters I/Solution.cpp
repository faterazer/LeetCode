#include <algorithm>
#include <array>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        array<unsigned, 26> seen { { 0 } };
        for (char c : word) {
            if (c >= 'a' && c <= 'z')
                seen[c - 'a'] |= 1;
            else
                seen[c - 'A'] |= 2;
        }
        return ranges::count(seen, 3);
    }
};
