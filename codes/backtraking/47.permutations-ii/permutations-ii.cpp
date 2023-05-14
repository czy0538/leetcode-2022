#include <vector>
#include <array>
#include <algorithm>
using namespace std;
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    array<bool, 8> used{};

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracing(nums);
        return result;
    }

    void backtracing(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (auto it = nums.begin(); it != nums.end(); it++) {
            // 单纯的相等，并不能说明同一层重复，因为我们每次是从第一个开始的。
            // 而如果是 false，那说明这一层一定是用过了。
            // 因为我们是从上面下来的，对于上面用过的元素，肯定是 true。会由下面的 if 逻辑跳过。
            // 而如果是 false 的，第一次遇到的时候肯定处理了，后面再次遇到那肯定是需要去重的。
            // 这个题是层内不能使用相同值的元素，层间不能使用相同位置的元素。
            
            // 去层内的相同值
            if (it != nums.begin() && *it == *(it - 1)&&used[it-1-nums.begin()]==false) {
                continue;
            }
            // 去层间的相同位置
            if(used[it-nums.begin()]==false){
                path.push_back(*it);
                used[it - nums.begin()] = true;
                backtracing(nums);
                used[it - nums.begin()] = false;
                path.pop_back();
            }
        }
    }
};