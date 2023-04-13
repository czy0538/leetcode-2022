#include <queue>
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

// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         bool hasNull = false;
//         while (!q.empty()) {
//             int n = q.size();
//             bool hasNum = false;
//             for (int i = 0; i < n; i++) {
//                 auto cur = q.front();
//                 q.pop();
//                 if (!cur) {
//                     hasNull = true;
//                     q.push(nullptr);
//                     q.push(nullptr);
//                 } else if (hasNull) {
//                     return false;
//                 } else {
//                     q.push(cur->left);
//                     q.push(cur->right);
//                     hasNum = true;
//                 }
//             }
//             if (!hasNum) {
//                 return true;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool hasNull = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (!cur) {
                hasNull = true;
            } else if (hasNull) {
                return false;
            } else {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
};