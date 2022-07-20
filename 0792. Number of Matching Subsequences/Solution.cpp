#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq_MK1(string s, vector<string>& words)
    {
        int res = 0;
        unordered_map<string, int> cnt;
        for (const string& word : words)
            ++cnt[word];
        for (const auto& it : cnt)
            if (isSubseq(s, it.first))
                res += it.second;
        return res;
    }

    int numMatchingSubseq_MK2(string s, vector<string>& words)
    {
        vector<vector<int>> indices(26);
        for (size_t i = 0; i < s.size(); ++i)
            indices[s[i] - 'a'].emplace_back(i);

        int res = 0;
        unordered_map<string, int> cnt;
        for (const string& word : words)
            ++cnt[word];
        for (const auto& it : cnt) {
            int idx = -1;
            bool flag = true;
            for (const char& c : it.first) {
                vector<int>& tmp = indices[c - 'a'];
                auto next_ptr = upper_bound(tmp.begin(), tmp.end(), idx);
                if (next_ptr == tmp.end()) {
                    flag = false;
                    break;
                }
                idx = *next_ptr;
            }
            if (flag)
                res += it.second;
        }
        return res;
    }

    int numMatchingSubseq_MK3(string s, vector<string>& words)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(26, -1));
        for (int i = dp.size() - 2; i >= 0; --i) {
            dp[i] = dp[i + 1];
            dp[i][s[i] - 'a'] = i + 1;
        }

        int res = 0;
        unordered_map<string, int> cnt;
        for (const string& word : words)
            ++cnt[word];
        for (const auto& it : cnt) {
            int idx = 0;
            for (const char& c : it.first) {
                idx = dp[idx][c - 'a'];
                if (idx == -1)
                    break;
            }
            if (idx != -1)
                res += it.second;
        }
        return res;
    }

    int numMatchingSubseq_MK4(string s, vector<string>& words)
    {
        vector<deque<pair<string, int>>> buff(26);
        unordered_map<string, int> cnt;
        for (const string& word : words)
            ++cnt[word];
        for (const auto& it : cnt)
            buff[it.first[0] - 'a'].emplace_back(it.first, 0);

        int res = 0;
        for (const char& c : s) {
            deque<pair<string, int>>& dq = buff[c - 'a'];
            int n = dq.size();
            for (int i = 0; i < n; ++i) {
                pair<string, int> p = dq.front();
                dq.pop_front();
                ++p.second;
                if (p.second == p.first.size())
                    res += cnt[p.first];
                else
                    buff[p.first[p.second] - 'a'].emplace_back(p);
            }
        }
        return res;
    }

private:
    bool isSubseq(const string& s, const string& t)
    {
        int si = 0, ti = 0, sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] == t[ti])
                ++ti;
            ++si;
        }
        return ti == tn;
    }
};
