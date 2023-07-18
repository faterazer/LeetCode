#include <string>
#include <vector>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs)
    {
        string res;
        for (const string &s : strs) {
            res += to_string(s.size()) + "/" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> res;
        size_t i = 0;
        while (i < s.size()) {
            int j = s.find('/', i);
            int n = stoi(s.substr(i, j - i));
            res.emplace_back(s.substr(j + 1, n));
            i = j + n + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
