#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string entityParser(string text)
    {
        string res;
        for (size_t i = 0; i < text.size(); ++i) {
            if (text[i] == '&') {
                size_t j = text.find(';', i + 1);
                if (j != string::npos) {
                    string substr = text.substr(i, j - i + 1);
                    if (mapper.count(substr)) {
                        res.push_back(mapper[substr]);
                        i = j;
                        continue;
                    }
                }
            }
            res.push_back(text[i]);
        }
        return res;
    }

private:
    unordered_map<string, char> mapper { { "&quot;", '"' }, { "&apos;", '\'' }, { "&amp;", '&' }, { "&gt;", '>' }, { "&lt;", '<' }, { "&frasl;", '/' } };
};
