#include <queue>
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
    int targetSum;
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        this->targetSum = targetSum;
        return preOrder(root,0);
    }
    bool preOrder(TreeNode *node, int cur) {
        cur += node->val;
        if (!node->left && !node->right && cur == targetSum) {
            return true;
        }
        bool result = false;

        if (node->left) {
            result |= preOrder(node->left, cur);
        }
        if (node->right) {
            result |= preOrder(node->right, cur);
        }
        return result;
    }
};