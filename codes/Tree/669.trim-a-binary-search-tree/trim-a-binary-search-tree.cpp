using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
    }
};

// 这个代码无法通过如下例子：
// [1, null, 2] 2 4
// 但 debug 的话其实发现没有问题的
// 删掉处理删除的部分就可以了。
// leetcode 中其实不太在乎野指针等等问题
// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if (!root) {
//             return nullptr;
//         }
//         if (root->val < low) {
//             auto cur = trimBST(root->right, low, high);
//             deleteTree(root->left);
//             delete root;
//             return cur;
//         } else if (root->val > high) {
//             auto cur = trimBST(root->left, low, high);
//             deleteTree(root->right);
//             delete (root);
//             return cur;
//         } else {
//             root->left = trimBST(root->left, low, high);
//             root->right = trimBST(root->right, low, high);
//         }
//         return root;
//     }

//     void deleteTree(TreeNode* root) {
//         if (!root) {
//             return;
//         }
//         deleteTree(root->left);
//         deleteTree(root->right);
//         delete root;
//     }
// };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) {
            return nullptr;
        }
        if (root->val < low) {
            auto cur = trimBST(root->right, low, high);
            return cur;
        } else if (root->val > high) {
            auto cur = trimBST(root->left, low, high);
            return cur;
        } else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};