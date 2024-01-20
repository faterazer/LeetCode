#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator)
    {
        vector<string> res;
        for (const string& w : words) {
            istringstream in(w);
            string sub;
            while (getline(in, sub, separator))
                if (!sub.empty())
                    res.emplace_back(sub);
        }
        return res;
    }
};
