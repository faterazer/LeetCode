#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right)
    {
        int res = 0;
        const string vowels = "aeiou";
        for (int i = left; i <= right; i++) {
            string& s = words[i];
            res += vowels.find(s[0]) != string::npos && vowels.find(s.back()) != string::npos;
        }
        return res;
    }
};
