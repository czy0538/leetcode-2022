#include <vector>

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
    int targetSum = 0;
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return result;
        }
        this->targetSum = targetSum;
        preOrder(root, 0, vector<int>());
        return result;
    }

    void preOrder(TreeNode *node, int cur, vector<int> path) {
        cur += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && cur == targetSum) {
            result.push_back(path);
            return;
        }
        if (node->left) {
            preOrder(node->left, cur, path);
        }
        if (node->right) {
            preOrder(node->right, cur, path);
        }
    }
};