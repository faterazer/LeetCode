#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

struct TrieNode {
    set<int> memo;
    vector<TrieNode*> children;

    TrieNode()
        : children(26, nullptr)
    {
    }
};

class WordFilter {
public:
    WordFilter(vector<string>& words)
    {
        unordered_map<string, int> s2idx;
        for (size_t i = 0; i < words.size(); ++i)
            s2idx[words[i]] = i;
        for (const auto &it : s2idx) {
            string word = it.first;
            int idx = it.second;
            TrieNode* cur = front_root;
            for (size_t i = 0; i < word.size(); ++i) {
                if (!cur->children[word[i] - 'a'])
                    cur->children[word[i] - 'a'] = new TrieNode();
                cur = cur->children[word[i] - 'a'];
                cur->memo.emplace(idx);
            }

            cur = back_root;
            for (int i = word.size() - 1; i >= 0; --i) {
                if (!cur->children[word[i] - 'a'])
                    cur->children[word[i] - 'a'] = new TrieNode();
                cur = cur->children[word[i] - 'a'];
                cur->memo.emplace(idx);
            }
        }
    }

    int f(const string &pref, const string &suff)
    {
        TrieNode *cur = front_root;
        for (const char c : pref) {
            if (!cur->children[c - 'a'])
                return -1;
            cur = cur->children[c - 'a'];
        }
        set<int> &candidates = cur->memo;

        cur = back_root;
        for (int i = suff.size() - 1; i >= 0; --i) {
            if (!cur->children[suff[i] - 'a'])
                return - 1;
            cur = cur->children[suff[i] - 'a'];
        }
        
        for (auto it = cur->memo.crbegin(); it != cur->memo.crend(); ++it)
            if (candidates.count(*it))
                return *it;
        return -1;
    }

private:
    TrieNode *front_root = new TrieNode(), *back_root = new TrieNode();
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
