#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        int last = logs.size() - 1;
        for (int i = last; i >= 0; i--) {
            int idx = logs[i].find(' ');
            if (isdigit(logs[i][idx + 1]))
                swap(logs[last--], logs[i]);
        }
        sort(logs.begin(), logs.begin() + last + 1, [](const string &a, const string &b) {
            size_t ai = a.find(' '), bi = b.find(' ');
            int r = strcmp(a.c_str() + ai, b.c_str() + bi);
            if (r != 0)
                return r < 0 ? true : false;
            else
                return a < b;
        });
        return logs;
    }
};
