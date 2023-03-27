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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) {
            return ans;
        }
        DFS(root, string());
        return ans;
    }

    void DFS(TreeNode *node, string cur) {
        cur = cur + to_string(node->val) + "->";
        if (!node->left && !node->right) {
            ans.push_back(cur.substr(0,cur.size()-2));
            return;
        }
        if (node->left) {
            DFS(node->left, cur);
        }
        if (node->right) {
            DFS(node->right, cur);
        }
    }
};