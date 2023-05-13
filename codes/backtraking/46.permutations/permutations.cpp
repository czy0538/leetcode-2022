#include <vector>
#include <array>
#include <algorithm>
using namespace std;

// 这个题跟前面的题不一样，这里的思想是纵向的不能重复
// 这个做法是考虑把这些元素往一个个空里填，填到所有元素都用过了位置
// 用过的做好标记，以免重复使用。
// class Solution {
//     vector<vector<int>> result;
//     vector<int> path;
//     array<bool, 21> used{};
//     using vit = vector<int>::const_iterator;

// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         backtracing(nums.cbegin(), nums.cend());
//         return result;
//     }

//     void backtracing(vit beg, vit end) {
//         for (auto it = beg; it < end; it++) {
//             if (used[*it + 10]) {
//                 continue;
//             }
//             used[*it + 10] = true;
//             path.push_back(*it);
//             backtracing(beg, end);
//             used[*it + 10] = false;
//             path.pop_back();
//         }
//         if(path.size()==end-beg){
//             result.push_back(path);
//         }
//     }
// };

// 另一个想法是交换位置，第i个元素分别在 0,1,2，。。。，n 个位置上
// 第一层就是让第一个元素分别在所有的位置
// 对于第二层，由于是交换，第一层的第二次交换，会交换 1,2。因此进入到第二层以后，没必要再跟前面的进行交换了。
// 构成的东西像是一个下三角方阵一样
class Solution {
    vector<vector<int>> result;
    using vit = vector<int>::iterator;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtracing(nums.begin(), nums);
        return result;
    }
    void backtracing(vit beg, vector<int>& nums) {
        if (beg == nums.end()) {
            result.push_back(nums);
            return;
        }
        for (auto it = beg; it != nums.end(); it++) {
            // swap(beg, it) 会导致只交换迭代器
            swap(*beg, *it);
            backtracing(beg + 1, nums);
            swap(*beg, *it);
        }
    }
};
