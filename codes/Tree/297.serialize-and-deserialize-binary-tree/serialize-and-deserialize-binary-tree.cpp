#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
// 因为编解码的方式我们都知道，其实一个前序遍历再恢复就足够了

class Codec {
public:
    // Encodes a tree to a single string.
    void preorder_serialize(TreeNode* root, string& str) {
        if (!root) {
            str += ",";
            return;
        }
        str += to_string(root->val);
        str += ",";
        preorder_serialize(root->left, str);
        preorder_serialize(root->right, str);
    }
    string serialize(TreeNode* root) {
        string ans;
        if (!root) {
            return ans;
        }
        preorder_serialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return nullptr;
        }
        int beg = 0;
        return preorder_deserialize(data, beg);
    }
    // 使用引用
    TreeNode* preorder_deserialize(string &data, int& beg) {
        // 这里不用担心字符串会溢出，因为到最后结尾的时候一定不会再有去 find 的情况了。这是由构造顺序保证的。
        auto pos = data.find(',', beg);
        if (pos == beg) {
            beg = pos + 1;
            return nullptr;
        }

        auto cur = new TreeNode(stoi(data.substr(beg, pos - beg)));
        beg = pos + 1;
        cur->left = preorder_deserialize(data, beg);
        cur->right = preorder_deserialize(data, beg);
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));