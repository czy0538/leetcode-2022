#include <vector>
#include <algorithm>
#include <iterator>
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
    using vi = vector<int>::iterator;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return pre_in(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    TreeNode *pre_in(vi pre_beg, vi pre_end, vi in_beg, vi in_end) {
        if (pre_beg == pre_end) {
            return nullptr;
        }
        auto root = new TreeNode(*pre_beg);
        if (pre_end - pre_beg == 1) {
            return root;
        }

        auto pos = find(in_beg, in_end, root->val);

        root->left = pre_in(pre_beg + 1, pre_beg + 1 + (pos - in_beg), in_beg, pos);
        root->right = pre_in(pre_beg + 1 + (pos - in_beg), pre_end, pos + 1, in_end);
        return root;
    }
};