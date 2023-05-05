#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    using vit = vector<int>::const_iterator;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracing(candidates.cbegin(), candidates.cend(), target);
        return result;
    }
    void backtracing(vit beg, vit end, int target) {
        if (beg == end) {
            return;
        }
        for (auto it = beg; it != end; it++) {
            // 同层去重，而树枝上不去重
            // 同层相当于第 i 个位置上，第 i 个位置上的元素是不能重复的，这依赖于数组是排序的。
            if (it > beg && *it == *(it-1)) {
                continue;
            }
            auto val = target - *it;
            if (val < 0) {
                return;
            }
            path.push_back(*it);
            backtracing(it + 1, end, val);
            if (val == 0) {
                result.push_back(path);
            }
            path.pop_back();
        }
    }
};