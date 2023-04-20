#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
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
    int sum = 0;
    int cur = 0;
    int sumNumbers(TreeNode *root) {
        if(!root){
            return 0;
        }
        dfs(root);
        return sum;
    }
    void dfs(TreeNode *root) {
        cur = cur * 10 + root->val;
        if(!root->left&&!root->right){
            sum += cur;
            cur /= 10;
            return;
        }
        if(root->left){
            dfs(root->left);
        }
        if(root->right){
            dfs(root->right);
        }
        cur /= 10;
    }
};