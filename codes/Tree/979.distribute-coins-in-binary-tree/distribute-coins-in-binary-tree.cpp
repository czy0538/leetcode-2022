#include <list>
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

class Solution {
    int ans = 0;

public:
    int distributeCoins(TreeNode* root) {
        postorder(root);
        return ans;
    }
    int postorder(TreeNode* node) {
        if (!node) {
            return 0;
        }
        auto moveleft = postorder(node->left);
        auto moveright = postorder(node->right);
        ans += abs(moveleft) + abs(moveright);
        return moveleft + moveright + node->val - 1;
    }
};