#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Trie {
    bool is_end;
    vector<Trie*> children;

    Trie()
        : is_end(false)
        , children(26, nullptr)
    {
    }
};

class MagicDictionary {
public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for (const string& word : dictionary) {
            Trie* cur = root;
            for (const char& c : word) {
                int idx = c - 'a';
                if (!cur->children[idx])
                    cur->children[idx] = new Trie;
                cur = cur->children[idx];
            }
            cur->is_end = true;
        }
    }

    bool search(string searchWord)
    {
        return dfs(root, searchWord, 0, 1);
    }

private:
    bool dfs(Trie* root, const string& word, int idx, int limit)
    {
        if (idx == word.size())
            return root->is_end && limit == 0;
        int i = word[idx] - 'a';
        if (root->children[i] && dfs(root->children[i], word, idx + 1, limit))
            return true;
        if (limit > 0) {
            for (int j = 0; j < 26; ++j)
                if (i != j && root->children[j] && dfs(root->children[j], word, idx + 1, limit - 1))
                    return true;
        }
        return false;
    }

    Trie* root = new Trie();
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
