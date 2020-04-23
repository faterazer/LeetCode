#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine);
};

bool Solution::canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> counter;
    for (const char &ch : magazine)
        counter[ch]++;
    for (const char &ch : ransomNote) {
        if (!counter.count(ch) || counter[ch] == 0)
            return false;
        counter[ch]--;
    }
    return true;
}
