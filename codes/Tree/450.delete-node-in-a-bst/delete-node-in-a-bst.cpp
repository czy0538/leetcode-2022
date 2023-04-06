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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(root->val==key){
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }else if(root->left&&!root->right){
                auto cur=root->left;
                delete root;
                return cur;
            }else if(!root->left&&root->right){
                auto cur=root->right;
                delete root;
                return cur;
            }else{
                auto cur=root->right;
                while(cur->left){
                    cur=cur->left;
                }
                cur->left=root->left;
                cur=root->right;
                delete root;
                return cur;
            }
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;

    }
};