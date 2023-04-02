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
class Solution {
public:
    TreeNode *pre;
    int getMinimumDifference(TreeNode *root) {
        if (!root) {
            return INT_MAX;
        }
        auto sub = getMinimumDifference(root->left);
        if (pre) {
            sub = min(sub, root->val - pre->val);
        }
        pre = root;
        return min(sub, getMinimumDifference(root->right));
    }
};