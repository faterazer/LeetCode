#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        struct Node {
            Node* children[26] {};
            int score = 0;
        };

        Node* root = new Node();
        for (const string& word : words) {
            Node* cur = root;
            for (char c : word) {
                int i = c - 'a';
                if (!cur->children[i])
                    cur->children[i] = new Node();
                cur = cur->children[i];
                ++cur->score;
            }
        }

        vector<int> ans(words.size());
        for (size_t i = 0; i < words.size(); ++i) {
            Node* cur = root;
            for (char c : words[i]) {
                cur = cur->children[c - 'a'];
                ans[i] += cur->score;
            }
        }
        return ans;
    }
};
