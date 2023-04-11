using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

// 这构建了一个新的树，原题目要是应该是可以在原树上修改。
// class Solution {
// public:
//     int sum = 0;
//     TreeNode *convertBST(TreeNode *root) {
//         if (!root) {
//             return nullptr;
//         }
//         auto cur = new TreeNode();
//         cur->right = convertBST(root->right);
//         cur->val = sum + root->val;
//         sum = cur->val;
//         cur->left = convertBST(root->left);
//         return cur;
//     }
// };

class Solution {
public:
    int sum = 0;
    TreeNode *convertBST(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        inorder(root);
        return root;
    }
    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->right);
        root->val = sum + root->val;
        sum = root->val;
        inorder(root->left);
    }
};