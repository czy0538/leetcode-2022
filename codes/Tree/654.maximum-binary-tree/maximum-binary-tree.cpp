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
    using vt = vector<int>::iterator;
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return buildTree(nums.begin(), nums.end());
    }

    TreeNode *buildTree(vt beg, vt end) {
        if (beg==end){
            return nullptr;
        }
        auto pos = max_element(beg, end);// 找出一个范围内的最大值，max 只能处理两个元素的最大值
        auto node = new TreeNode(*pos);
        if (end - beg == 1) {
            return node;
        }
        node->left = buildTree(beg, pos);
        node->right = buildTree(pos + 1, end);
        return node;
    }
};