#include <stack>
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

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        return getHeight(root) == -1 ? false : true;
    }
    int getHeight(TreeNode *node) {
        if (!node) {
            return 0;
        }
        auto leftHeight = getHeight(node->left);
        if(leftHeight==-1){
            return -1;
        }
        auto rightHeight = getHeight(node->right);
        if(rightHeight==-1){
            return -1;
        }
        return abs(leftHeight - rightHeight) > 1 ? -1 : max(leftHeight, rightHeight) + 1;
    }
};