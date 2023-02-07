#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime)
    {
        int n = keyName.size();
        unordered_map<string, vector<int>> dict;
        for (int i = 0; i < n; i++) {
            string &name = keyName[i], &time = keyTime[i];
            dict[name].emplace_back(minutesOfDay(time));
        }

        vector<string> res;
        for (auto& it : dict) {
            sort(it.second.begin(), it.second.end());
            for (size_t i = 2; i < it.second.size(); i++) {
                if (it.second[i] - it.second[i - 2] <= 60) {
                    res.emplace_back(it.first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

private:
    int minutesOfDay(const string& time)
    {
        int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3, 2));
        return h * 60 + m;
    }
};
