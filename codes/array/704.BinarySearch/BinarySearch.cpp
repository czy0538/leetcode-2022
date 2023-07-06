#include <iostream>
#include <vector>
#include <fmt/core.h>
using namespace std;
// 2023年07月06日 修改为 acwing版本
// 找右边界
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int mid, l = 0, r = nums.size() - 1;
//         while (l < r) {
//             mid = l + r + 1 >> 1;
//             if (nums[mid] <= target) {
//                 l = mid;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         if (nums[l] == target) {
//             return l;
//         }
//         return -1;
//     }
// };

// 找左边界
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, l = 0, r = nums.size() - 1;
        while (l < r) {
            mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
};