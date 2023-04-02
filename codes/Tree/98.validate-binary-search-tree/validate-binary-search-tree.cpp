#include <vector>
#include <algorithm>
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



// 错误写法，只能判断一层，不能判断所有子树。
// class Solution {
// public:
//     bool isValidBST(TreeNode *root) {
//         if (!root) {
//             return true;
//         }

//         if (root->left && root->right) {
//             return root->left->val < root->val && root->val < root->right->val && isValidBST(root->left)
//                    && isValidBST(root->right);
//         } else if (root->left && !root->right) {
//             return root->left->val < root->val && isValidBST(root->left);
//         }else if(!root->left&&root->right){
//             return root->val < root->right->val && isValidBST(root->right);
//         }else{
//             return true;
//         }
//     }
// };

// 二叉搜索树「中序遍历」得到的值构成的序列一定是升序的，这启示我们在中序遍历的时候实时检查当前节点的值是否大于前一个中序遍历到的节点的值即可。如果均大于说明这个序列是升序的，整棵树是二叉搜索树，否则不是，

class Solution {
public:
    TreeNode *pre;
    bool isValidBST(TreeNode *root) {
        if(!root){
            return true;
        }
        auto left = isValidBST(root->left);
        if(pre&&pre->val>=root->val){
            return false;
        }
        pre = root;
        auto right = isValidBST(root->right);
        return left && right;
    }
};