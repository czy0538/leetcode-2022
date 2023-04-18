#include <initializer_list> // 头文件
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

// 最朴素的比较法，采用后续遍历即可
// class Solution {
// public:
//     int maxSum = -1000;
//     int maxPathSum(TreeNode *root) {
//         maxVal(root);
//         return maxSum;
//     }
//     int maxVal(TreeNode *root) {
//         if (!root) {
//             return -1000;
//         }
//         auto left = maxVal(root->left);
//         auto right = maxVal(root->right);
//         auto curMax = max({root->val,left + root->val, right + root->val});
//         maxSum = max({maxSum, left, right, curMax , left + right + root->val});
//         return curMax;
//     }
// };

// 上面的方法可以，但是多了很多多余的比较的过程
// 这里，我们其实需要的子树，是对我们的最大值有贡献的子树
// 这里的贡献指的是能够提供一个正的值，也就是说如果当前的某个子树提供的是负数，那么其实这个子树没有贡献，也就是没有意义的。
class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode *root) {
        maxVal(root);
        return maxSum;
    }

    int maxVal(TreeNode *root) {
        if (!root) {
            return INT_MIN; // 空子树没有贡献
        }
        // 对于子树，我们只要有贡献的
        auto left = max(maxVal(root->left), 0);
        auto right = max(maxVal(root->right), 0);
        // 更新当前的最大值
        // 对于叶子结点，当前值即为最大值
        // 对于非叶子结点，如果左或右为最大值，那么在以其为根的子树中已经考虑过了，这里仅需要考虑当前子树即可
        maxSum = max(maxSum, root->val + left + right);
        // 返回的时候，由于每个节点只能走一次，因此只有贡献最大的才能加入路径
        return root->val + max(left, right);
    }
};