#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding_MK1(vector<string> &words);   // 暴力哈希
    int minimumLengthEncoding_MK2(vector<string> &words);   // Tire
    int minimumLengthEncoding_MK3(vector<string> &words);   // 反转
};

int Solution::minimumLengthEncoding_MK1(vector<string> &words)
{
    unordered_set<string> hash(words.begin(), words.end());
    for (const string &word : words) {
        for (size_t i = 1; i < word.size(); i++)
            hash.erase(word.substr(i));
    }
    int ans = 0;
    for (const string &word : hash)
        ans += word.size() + 1;
    return ans;
}

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
};

int Solution::minimumLengthEncoding_MK2(vector<string> &words)
{
    TrieNode *root = new TrieNode;
    vector<pair<TrieNode*, int>> leaves;
    for (const string &word : unordered_set<string>(words.begin(), words.end())) {
        TrieNode *curr = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            if (curr->children.count(word[i]) == 0)
                curr->children[word[i]] = new TrieNode;
            curr = curr->children[word[i]];
        }
        leaves.emplace_back(make_pair(curr, word.size() + 1));
    }

    int ans = 0;
    for (const pair<TrieNode*, int> &leaf : leaves)
        if (!leaf.first->children.size())
            ans += leaf.second;
    return ans;
}

bool comp(const string &left, const string &right)
{
    int n1 = left.size(), n2 = right.size();
    for (int i = 0; i < min(n1, n2); i++) {
        char c1 = left[n1 - i - 1];
        char c2 = right[n2 - i - 1];
        if (c1 != c2)
            return c1 < c2;
    }
    return n1 < n2;
}

bool endWith(const string &s1, const string &s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 < n2)
        return false;
    for (int i = 0; i < n2; i++)
        if (s1[n1 - n2 + i] != s2[i])
            return false;
    return true;
}

int Solution::minimumLengthEncoding_MK3(vector<string> &words)
{
    sort(words.begin(), words.end(), comp);
    int ans = 0;
    for (size_t i = 0; i < words.size(); i++)
        if (i == words.size() - 1 || !endWith(words[i + 1], words[i]))
            ans += words[i].size() + 1;
    return ans;
}
