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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If root is p or q or empty, return root itself.
        if (root == p || root == q || !root) {
            return root;
        }
        // post order traversal
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // both left and right not nullptr, it means p and q was found in root's child,so the root is target.
        if(left&&right){
            return root;
        }

        // if left is nullptr, so the result may contain in right,or no target in left.
        // no matter right is answer or nullptr or answer, you always need to return it.
        if(!left){
            return right;
        }
        return left;

    }
};