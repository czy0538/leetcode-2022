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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> q;
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        bool isl2r = true;
        q.push_back(root);
        while (!q.empty()) {
            vector<TreeNode*> tmp;
            vector<int> curval(q.size());
            for (int i = 0; i < q.size(); i++) {
                if (isl2r) {
                    curval[i] = q[i]->val;

                } else {
                    curval[q.size() - i - 1] = q[i]->val;
                }
                if (q[i]->left) {
                    tmp.push_back(q[i]->left);
                }
                if (q[i]->right) {
                    tmp.push_back(q[i]->right);
                }
            }
            result.push_back(move(curval));
            q = move(tmp);
            isl2r = !isl2r;
        }
        return result;
    }
};