#include <vector>
#include <string>
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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return postOrder(root, false);
    }
    int postOrder(TreeNode *node, bool isLeft) {
        int tmp = 0;
        if (!node->left && !node->right && isLeft) {
            return node->val;
        }
        if (node->left) {
            tmp += postOrder(node->left, true);
        }
        if (node->right) {
            tmp += postOrder(node->right, false);
        }
        return tmp;
    }
};