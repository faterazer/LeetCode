#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> counter;
        for (string cpdomain : cpdomains) {
            int spaceIndex = cpdomain.find(' ');
            int cnt = stoi(cpdomain.substr(0, spaceIndex));
            string domain = cpdomain.substr(spaceIndex + 1);
            counter[domain] += cnt;
            for (size_t i = domain.find('.'); i != string::npos; i = domain.find('.', i))
                counter[domain.substr(++i)] += cnt;
        }
        vector<string> ret;
        for (auto it : counter)
            ret.emplace_back(to_string(it.second) + " " + it.first);
        return ret;
    }
};
