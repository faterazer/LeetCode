#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix_MK1(vector<string> &);
    string longestCommonPrefix_MK2(vector<string> &);
    string longestCommonPrefix_MK3(vector<string> &);
    string longestCommonPrefix_MK4(vector<string> &);
  private:
    string commonPrefix(const string &, const string &);
    string longestCommonPrefix(vector<string> &, size_t, size_t);
};

int main(int argc, char const *argv[])
{
    vector<string> test1 = { "flower", "flow", "flight" };
    cout << Solution().longestCommonPrefix_MK1(test1) << endl;

    vector<string> test2 = { "dog", "racecar", "car" };
    cout << Solution().longestCommonPrefix_MK1(test2) << endl;

    vector<string> test3 = { "" };
    cout << Solution().longestCommonPrefix_MK1(test3) << endl;

    vector<string> test4 = { "aaaaa", "aaaaa", "aaaaa", "aaaaa", "aaaaa" };
    cout << Solution().longestCommonPrefix_MK1(test4) << endl;

    vector<string> test5 = {};
    cout << Solution().longestCommonPrefix_MK1(test5) << endl;

    vector<string> test6 = { "a", "b" };
    cout << Solution().longestCommonPrefix_MK1(test6) << endl;
    return 0;
}

// Horizontal scanning
string Solution::longestCommonPrefix_MK1(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0];
    for (size_t i = 1; i < strs.size(); i++)
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty())
                return "";
        }
    return prefix;
}

// Vertical scanning
string Solution::longestCommonPrefix_MK2(vector<string> &strs)
{
    if (strs.empty() || strs[0].empty())
        return "";

    for (size_t i = 0; i < strs[0].size(); i++) {
        for (size_t j = 1; j < strs.size(); j++)
            if (i > strs[j].size()-1 || strs[j][i] != strs[0][i])
                return strs[0].substr(0, i);
    }
    return strs[0];
}

// Divide and conquer
string Solution::longestCommonPrefix_MK3(vector<string> &strs)
{
    if (strs.empty())
        return "";

    size_t left = 0, right = strs.size() - 1;
    return longestCommonPrefix(strs, left, right);
}

string Solution::longestCommonPrefix(vector<string> &strs, size_t left, size_t right)
{
    if (left < right) {
        size_t mid = (left + right) / 2;
        string lstring = longestCommonPrefix(strs, left, mid);
        string rstring = longestCommonPrefix(strs, mid+1, right);
        return commonPrefix(lstring, rstring);
    }
    else
        return strs[left];
}

string Solution::commonPrefix(const string &s1, const string &s2)
{
    string prefix = s1;
    while(s2.find(prefix) != 0){
        prefix = prefix.substr(0, prefix.size()-1);
        if (prefix.empty())
            return "";
    }
    return prefix;
}

// Binary search
string Solution::longestCommonPrefix_MK4(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string first = strs.front();
    size_t left = 0, right = strs.front().size();

    while (left <= right) {
        size_t mid = (left + right) / 2;
        string prefix = first.substr(0, mid);

        size_t i;
        for (i = 1; i < strs.size() && strs[i].find(prefix) == 0; i++)
            ;

        if (i < strs.size())    // search failed
            right = mid - 1;
        else
            left = mid + 1;
    }
    return first.substr(0, (left + right) / 2);
}