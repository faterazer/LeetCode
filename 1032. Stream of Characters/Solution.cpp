#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words)
    {
        for (const string& word : words)
            update(root, word);
    }

    bool query(char letter)
    {
        char_stream.push_back(letter);
        TrieNode* p = root;
        for (int i = char_stream.size() - 1; i >= 0 && p; i--) {
            p = p->children[char_stream[i]];
            if (p && p->is_word)
                return true;
        }
        return false;
    }

private:
    void update(TrieNode* root, const string& word)
    {
        TrieNode* p = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            if (!p->children.count(word[i]))
                p->children[word[i]] = new TrieNode;
            p = p->children[word[i]];
        }
        p->is_word = true;
    }

    TrieNode* root = new TrieNode;
    string char_stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
