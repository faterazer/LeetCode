#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<string, vector<string>> mapper;
        for (const string& path : paths) {
            istringstream in(path);
            string dir_path, file;
            in >> dir_path;
            while (in >> file) {
                int l = file.find('('), r = file.find(')');
                string filename = file.substr(0, l - 1), content = file.substr(l + 1, r - l - 1);
                mapper[content].emplace_back(dir_path + '/' + filename);
            }
        }

        vector<vector<string>> res;
        for (const auto& it : mapper)
            if (it.second.size() > 1)
                res.emplace_back(it.second);
        return res;
    }
};
