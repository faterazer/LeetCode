#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        unordered_map<char, string> edges;
        unordered_map<char, int> in_degree;
        for (const string& w : words) {
            for (char c : w) {
                edges[c] = "";
                in_degree[c] = 0;
            }
        }

        for (size_t i = 1; i < words.size(); i++) {
            size_t j = 0;
            for (; j < words[i - 1].size() && j < words[i].size(); j++)
                if (words[i - 1][j] != words[i][j])
                    break;
            if (j == words[i - 1].size())
                continue;
            if (j == words[i].size())
                return "";

            char a = words[i - 1][j], b = words[i][j];
            edges[a].push_back(b);
            in_degree[b]++;
        }

        string res;
        for (int i = edges.size(); i > 0; i--) {
            int j = 0;
            for (; j < 26; j++)
                if (in_degree.count('a' + j) && in_degree['a' + j] == 0)
                    break;
            if (j == 26)
                return "";
            res.push_back('a' + j);
            for (char c : edges['a' + j])
                in_degree[c]--;
            edges.erase('a' + j);
            in_degree.erase('a' + j);
        }
        return res;
    }
};
