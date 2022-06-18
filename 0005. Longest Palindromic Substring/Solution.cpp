#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome_MK1(string s)
    {
        // Time complexity: O(n^2)
        // Space complexity: O(1)
        int n = s.size();
        pair<int, int> range;
        for (int i = 0; i < n; ++i) {
            pair<int, int> p = expandAroundCenter(s, i, i);
            if (range.second - range.first < p.second - p.first)
                range = p;
            p = expandAroundCenter(s, i, i + 1);
            if (range.second - range.first < p.second - p.first)
                range = p;
        }
        return s.substr(range.first, range.second - range.first + 1);
    }

    string longestPalindrome_MK2(string s)
    {
        /*
        Manacher
        Time complexity: O(n)
        Space complexity: O(n)
        */
        string ss(2 * s.size() + 1, '#');
        for (size_t i = 0; i < s.size(); ++i)
            ss[2 * i + 1] = s[i];

        vector<int> p(ss.size(), 0);
        int n = ss.size(), center = 0, max_right = 0;
        for (int i = 1; i < ss.size(); ++i) {
            if (i >= max_right) {
                center = i;
                max_right = expandAroundCenter(ss, i, i).second;
                p[i] = max_right - center;
            } else {
                p[i] = min(max_right - i, p[2 * center - i]);
                pair<int, int> range = expandAroundCenter(ss, i - p[i], i + p[i]);
                if (range.second > max_right) {
                    center = i;
                    max_right = range.second;
                }
                p[i] = range.second - i;
            }
        }

        int idx = max_element(p.begin(), p.end()) - p.begin();
        int beg = idx - p[idx], end = idx + p[idx];
        string res;
        for (int i = beg; i <= end; ++i)
            if (ss[i] != '#')
                res.push_back(ss[i]);
        return res;
    }

private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return make_pair(left + 1, right - 1);
    }
};
