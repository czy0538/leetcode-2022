#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 暴力遍历法，时间复杂度O(n2)，空间复杂度O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if(nums[i]+nums[j]==target){
//                     return vector<int>{i, j};
//                 }
//             }
//         }
//         return vector<int>();
//     }
// };

// 进阶版，先排序，然后二分查找
// 构建复杂度为O(n)，排序为O(nlogn)，二分查找为O(logn)，遍历为O(n)，因此时间复杂度度为O(nlogn)
// class Solution {
// public:
//     // 二分查找
//     int binary_find(vector<pair<int, int>>::iterator beg, vector<pair<int, int>>::iterator end, int target) {
//         int size = end - beg;
//         int l = 0, r = size;
//         int mid = (l + r) >> 1;
//         while (l < r) {
//             auto cur = (beg + mid);
//             if (cur->second == target) {
//                 return cur->first;
//             } else if (cur->second < target) {
//                 l = mid + 1;
//             } else {
//                 r = mid;
//             }
//             mid = (l + r) >> 1;
//         }
//         return -1;
//     }
//     vector<int> twoSum(vector<int> &nums, int target) {
//         vector<pair<int, int>> dict;
//         dict.reserve(nums.size());
//         // 通过pair保存原始的位置信息
//         for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
//             dict.push_back(pair<int, int>{i, nums[i]});
//         }

//         // 排序
//         sort(dict.begin(), dict.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
//             return a.second < b.second;
//         });

//         // 查找
//         for (auto iter = dict.begin(); iter != dict.end(); iter++) {
//             int n = target - iter->second;
//             int t = binary_find(iter + 1, dict.end(), n);
//             if (t != -1) {
//                 return vector<int>{iter->first, t};
//             }
//         }
//         return vector<int>();
//     }
// };

// 进一步优化，使用hash表代替了查找的过程，将查找的复杂度降低到O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> dict;
//         for (decltype(nums.size()) i = 0; i < nums.size();++i){
//             dict[nums[i]] = i;
//         }
//         for (int i = 0; i < nums.size(); ++i) {
//             auto j = dict.find(target - nums[i]);
//             if(j!=dict.end()&&j->second!=i){
//                 return vector<int>{i, j->second};
//             }
//         }
//         return vector<int>();
//     }
// };

// 最终优化版本，可以一边构建，一边查找
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};