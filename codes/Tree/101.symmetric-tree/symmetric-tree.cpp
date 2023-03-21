
#include <queue>
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

// 层序遍历，也不是不能过。但是效率太感动了。

// class Solution {
// public:
//     const int ILL = 10086;
//     bool isSymmetric(TreeNode *root) {
//         queue<TreeNode *> q;
//         q.push(root);
//         while (!q.empty()) {
//             auto size = q.size();
//             vector<int> tmp;
//             bool isEnd = true;
//             for (int i = 0; i < size; ++i) {
//                 auto cur = q.front();
//                 q.pop();
//                 if (cur == nullptr) {
//                     tmp.push_back(ILL);
//                     q.push(nullptr);
//                     q.push(nullptr);
//                 } else {
//                     tmp.push_back(cur->val);
//                     if (cur->left != nullptr) {
//                         q.push(cur->left);
//                         isEnd = false;
//                     } else {
//                         q.push(nullptr);
//                     }
//                     if (cur->right != nullptr) {
//                         q.push(cur->right);
//                         isEnd = false;
//                     } else {
//                         q.push(nullptr);
//                     }
//                 }
//             }
//             for (int i = 0, j = tmp.size() - 1; i < j; i++, j--) {
//                 if (tmp[i] != tmp[j]) {
//                     return false;
//                 }
//             }
//             if (isEnd) {
//                 break;
//             }
//         }
//         return true;
//     }
// };

// 递归法：理解起来不难，但是真的不容易想明白
// class Solution {
// public:
//     bool isSymmetric(TreeNode *root) {
//         if(root==nullptr){
//             return true;
//         }
//         return compare(root->left, root->right);
//     }
//     bool compare(TreeNode* left,TreeNode* right){
//         if (left==nullptr&&right==nullptr){
//             return true;
//         }else if(left!=nullptr&&right==nullptr||left==nullptr&&right!=nullptr){
//             return false;
//         }else{
//             if (left->val!=right->val){
//                 return false;
//             }
//             return compare(left->left, right->right) && compare(left->right, right->left);
//         }
//     }
// };

// 非递归法，只要保证了成对的比较就可以，其实用一个队列或者栈就可以了
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        queue<TreeNode *> left;
        queue<TreeNode *> right;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty()&&!right.empty()){
            auto l = left.front();
            left.pop();
            auto r = right.front();
            right.pop();
            if(l&&!r||!l&&r){
                return false;
            }else if(!l&&!r){
                continue;
            }else{
                if(l->val!=r->val){
                    return false;
                }else{
                    left.push(l->left);
                    right.push(r->right);
                    left.push(l->right);
                    right.push(r->left);
                }
            }
        }
        return left.empty() && right.empty();
    }
};