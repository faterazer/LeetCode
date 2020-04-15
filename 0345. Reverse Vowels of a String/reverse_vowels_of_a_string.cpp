#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s);
};

string Solution::reverseVowels(string s)
{
    int i = 0, j = s.size() - 1;
    string vowels = "aeiouAEIOU";
    while (i < j) {
        i = s.find_first_of(vowels, i);
        j = s.find_last_of(vowels, j);
        if (i < j)
            swap(s[i++], s[j--]);
    }
    return s;
}
