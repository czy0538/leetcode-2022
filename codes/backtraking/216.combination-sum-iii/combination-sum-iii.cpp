#include <vector>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
    void dfs(int k, int n, int beg) {
        if(k<1||beg>10){
            return;
        }
        for (int i = beg; i <= 9; i++) {
            int val = n - i;
            if(val<0||k>1&&val==0){
                return;
            }
            path.push_back(i);
            if (k == 1 && val == 0) {
                ans.push_back(path);
                path.pop_back();
                return;
            }
            dfs(k - 1, val, i + 1);
            path.pop_back();
        }
    }
};