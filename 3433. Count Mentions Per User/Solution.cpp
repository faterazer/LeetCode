#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events)
    {
        ranges::sort(events, [](const vector<string>& left, const vector<string>& right) {
            int left_timestamp = stoi(left[1]), right_timestamp = stoi(right[1]);
            if (left_timestamp != right_timestamp)
                return left_timestamp < right_timestamp;
            if (right[0] == "OFFLINE")
                return false;
            return true;
        });
        vector<int> mentions(numberOfUsers), online_t(numberOfUsers);
        int all_cnt = 0;
        for (const vector<string>& event : events) {
            string event_type = event[0];
            int timestamp = stoi(event[1]);
            if (event_type == "MESSAGE") {
                if (event[2] == "ALL")
                    ++all_cnt;
                else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i)
                        if (online_t[i] <= timestamp)
                            ++mentions[i];
                } else {
                    for (const auto& part : event[2] | ranges::views::split(' ')) {
                        int user = stoi(string(part.begin() + 2, part.end()));
                        ++mentions[user];
                    }
                }
            } else {
                int user = stoi(event[2]);
                online_t[user] = timestamp + 60;
            }
        }
        for (int& cnt : mentions)
            cnt += all_cnt;
        return mentions;
    }
};
