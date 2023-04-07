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
    using vi = vector<int>::iterator;
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums.begin(), nums.end());
    }
    TreeNode *build(vi beg, vi end) {
        if (beg == end) {
            return nullptr;
        }
        auto mid = beg + (end - beg) / 2;
        auto node = new TreeNode(*mid);
        node->left = build(beg, mid);
        node->right = build(mid+1,end);
        return node;
    }
};