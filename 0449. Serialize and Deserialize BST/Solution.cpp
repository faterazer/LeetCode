#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string res;
        serialize(root, res);
        return res;
    }

    void serialize(TreeNode* root, string& res)
    {
        if (!root) {
            res.push_back('0');
            return;
        }
        res.push_back('1');
        char buff[sizeof(root->val)];
        memcpy(buff, &root->val, sizeof(root->val));
        res.append(string(buff, sizeof(buff)));
        serialize(root->left, res);
        serialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data)
    {
        TreeNode* res = nullptr;
        int idx = 0;
        deserialize(res, data, idx);
        return res;
    }

    void deserialize(TreeNode*& res, const string &data, int &idx)
    {
        if (data[idx] == '0') {
            res = nullptr;
            idx++;
            return;
        }
        idx++;
        res = new TreeNode(0);
        memcpy(&res->val, data.c_str() + idx, sizeof(res->val));
        idx += sizeof(res->val);
        deserialize(res->left, data, idx);
        deserialize(res->right, data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
