#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    using vit = vector<int>::const_iterator;

public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracing(vit beg, vit end, int target) {
        for (auto &it = beg; it != end; it++) {
            auto cur = target - *it;
            if (cur < 0) {
                return;
            }
            path.push_back(*it);
            if (cur == 0) {
                result.push_back(path);
                path.pop_back();
                return;
            } else {
                backtracing(it, end, cur);
            }
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // 排序，目的是方便剪枝
        backtracing(candidates.cbegin(), candidates.cend(), target);
        return result;
    }
};