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
public:
    int ans = 0;
    int count = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        dfs(root->right, k);
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }
        dfs(root->left, k);
    }
};