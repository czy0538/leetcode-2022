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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return in_post(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode *in_post(vi in_beg, vi in_end, vi post_beg, vi post_end) {
        if (post_beg == post_end) {
            return nullptr;
        }
        auto root = new TreeNode(*(post_end - 1));

        if (1 == post_end - post_beg) {
            return root;
        }
        // 切割中序数组
        auto in_pos = find(in_beg, in_end, *(post_end - 1));

        root->left = in_post(in_beg, in_pos, post_beg, post_beg + (in_pos - in_beg));
        root->right = in_post(in_pos + 1, in_end, post_beg + (in_pos - in_beg), post_end - 1);
        return root;
    }
};