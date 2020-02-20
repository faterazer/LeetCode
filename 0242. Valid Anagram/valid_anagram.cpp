#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram_MK1(string s, string t); // Approach 1: Sorting
    bool isAnagram_MK2(string s, string t); // Approach 2: Hash Table
};

// Approach 1: Sorting
// Time complexity: O(nlgn)
// Space complexity: O(1)
bool Solution::isAnagram_MK1(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Approach 2: Hash Table
// Time complexity: O(n)
// Space complexity: O(1)
bool Solution::isAnagram_MK2(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> hash;
    for (const auto &ch : s) {
        if (hash.find(ch) == hash.end())
            hash[ch] = 1;
        else
            hash[ch]++;
    }
    for (const auto &ch : t) {
        if (hash.find(ch) == hash.end() || hash[ch] == 0)
            return false;
        hash[ch]--;
    }
    return true;
}
