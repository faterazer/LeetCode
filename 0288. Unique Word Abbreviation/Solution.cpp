#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary)
    {
        for (const string& s : dictionary) {
            string key = abbreviate(s);
            if (table.count(key) && table[key] != s)
                table[key] = "";
            else
                table[key] = s;
        }
    }

    bool isUnique(string word)
    {
        string key = abbreviate(word);
        if (!table.count(key) || table[key] == word)
            return true;
        return false;
    }

private:
    string abbreviate(const string& s)
    {
        return s.size() > 2 ? s[0] + to_string(s.size() - 2) + s.back() : s;
    }

    unordered_map<string, string> table;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
