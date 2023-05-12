#include <vector>
#include <unordered_set>
#include <array>
using namespace std;
// 使用 unordered_set 去重，适用于所有的情况，不要求提前排序
// class Solution {
//     using vit = vector<int>::const_iterator;
//     vector<int> path;
//     vector<vector<int>> result;

// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         backtracing(nums.cbegin(), nums.cend());
//         return result;
//     }

//     void backtracing(vit beg, vit end) {
//         if (beg == end) {
//             return;
//         }
//         unordered_set<int> used;
//         for (auto it = beg; it < end; it++) {
//             if (used.find(*it)!=used.end() || (!path.empty()&&*it < path.back())) {
//                 continue;
//             }
//             path.push_back(*it);
//             used.insert(*it);
//             if (path.size() > 1) {
//                 result.push_back(path);
//             }
//             backtracing(it + 1, end);
//             path.pop_back();
//         }
//     }
// };

// 使用数组也可以去重，但是要求必须是数据范围已知
class Solution {
    using vit = vector<int>::const_iterator;
    vector<int> path;
    vector<vector<int>> result;

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracing(nums.cbegin(), nums.cend());
        return result;
    }

    void backtracing(vit beg, vit end) {
        if (beg == end) {
            return;
        }
        array<bool, 201> used{};
        for (auto it = beg; it < end; it++) {
            if (used[*it+100] || (!path.empty() && *it < path.back())) {
                continue;
            }
            path.push_back(*it);
            used[*it + 100] = true;
            if (path.size() > 1) {
                result.push_back(path);
            }
            backtracing(it + 1, end);
            path.pop_back();
        }
    }
};