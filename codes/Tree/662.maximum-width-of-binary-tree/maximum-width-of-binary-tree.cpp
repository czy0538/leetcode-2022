#include <vector>
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

// 部分测试用例会超时
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         int maxWidth = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int size = q.size();
//             int wb = -1;
//             int we = -1;
//             for (int i = 0; i < size; ++i) {
//                 auto cur = q.front();
//                 q.pop();
//                 if(!cur){
//                     if(wb!=-1){
//                         q.push(nullptr);
//                         q.push(nullptr);
//                     }
//                 }else{
//                     if(wb==-1){
//                         wb = i;
//                     }else{
//                         we = i;
//                     }
//                     q.push(cur->left);
//                     q.push(cur->right);
//                 }
//             }
//             if(wb==-1){
//                 return maxWidth;
//             }else if(we==-1){
//                 maxWidth = max(1, maxWidth);
//             }else{
//                 maxWidth = max(we - wb + 1, maxWidth);
//             }
//         }
//         return maxWidth;
//     }
// };

class Solution {
public:
    using p = pair<TreeNode*, unsigned long long>;
    int widthOfBinaryTree(TreeNode* root) {
        vector<p> q;
        unsigned long long maxWidth = 0;
        q.emplace_back(root, 1);
        while (!q.empty()) {
            vector<p> tmp;
            for (auto& [node, index] : q) {
                if (node->left) {
                    // 给每个节点编上号，编完号以后通过编号进行判断
                    tmp.emplace_back(node->left, index * 2);
                }
                if (node->right) {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            maxWidth = max(q.back().second - q.front().second + 1, maxWidth);
            q = move(tmp);
        }
        return maxWidth;
    }
};

//  不能用队列，因为队列无法从尾部读取数据