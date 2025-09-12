#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s)
    {
        return ranges::any_of(s, [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; });
    }
};
