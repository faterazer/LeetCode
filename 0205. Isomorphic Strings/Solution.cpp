#include <map>
#include <set>
#include <string>
using namespace std;


class Solution {
public:
    bool isIsomorphic_MK1(string s, string t);
    bool isIsomorphic_MK2(string s, string t);
};

bool Solution::isIsomorphic_MK1(string s, string t)
{
    map<char, char> hash_map;
    set<char> hash_set;
    for (size_t i = 0; i < s.size(); i++) {
        if (hash_map.find(s[i]) == hash_map.end()) {
            if (hash_set.find(t[i]) != hash_set.end())
                return false;
            hash_map[s[i]] = t[i];
            hash_set.insert(t[i]);
        }
        else if (hash_map[s[i]] != t[i])
            return false;
    }
    return true;
}

bool Solution::isIsomorphic_MK2(string s, string t)
{
    for (size_t i = 0; i < s.size(); i++) {
        if (s.find(s[i]) != t.find(t[i]))
            return false;
    }
    return true;
}
